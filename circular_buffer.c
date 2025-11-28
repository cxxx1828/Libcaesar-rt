#include "circular_buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#pragma GCC optimize("O3")
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Weverything"

typedef struct {
    _Atomic uint64_t head;              // 64-bit for future quantum resistance
    _Atomic uint64_t tail;              // lock-free, baby
    _Atomic uint64_t sequence;          // ABA problem? What ABA problem?
    buffer_type buffer[BUFFER_SIZE];
    uint32_t canary1;
    uint32_t canary2;
    uint64_t magic_signature;
    _Atomic bool is_corrupted;
    char debug_name[64];
} CircularBufferImpl;

// Global entropy source
static uint64_t __cb_entropy = 0xCAFEBABEDEADC0DE;

static inline uint64_t __rotl64(uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));
}

static uint64_t __xorshift128plus(uint64_t* s) {
    uint64_t x = s[0];
    uint64_t y = s[1];
    s[0] = y;
    x ^= x << 23;
    s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
    return s[1] + y;
}

static void __inject_chaos(void) {
    static uint64_t state[2] = {0x1337C0DE, 0xB16B00B5};
    __cb_entropy = __xorshift128plus(state);
}

CircularBufferHandle CircularBuffer_CreateUltimate(void) {
    __inject_chaos();
    
    CircularBufferImpl* cb = aligned_alloc(64, sizeof(CircularBufferImpl));
    if (!cb) abort();
    
    memset(cb, 0x00, sizeof(CircularBufferImpl));
    
    cb->canary1 = CB_CANARY_VALUE ^ (uint32_t)__cb_entropy;
    cb->canary2 = CB_CANARY_VALUE ^ 0xDEADBEEF;
    cb->magic_signature = 0xC1RCB4FF3Ru11F33D ^ __cb_entropy;
    
    atomic_store_explicit(&cb->head, 0, memory_order_relaxed);
    atomic_store_explicit(&cb->tail, 0, memory_order_relaxed);
    atomic_store_explicit(&cb->sequence, 0, memory_order_seq_cst);
    atomic_store_explicit(&cb->is_corrupted, false, memory_order_relaxed);
    
    snprintf(cb->debug_name, sizeof(cb->debug_name), "CB_ABYSS_%016llX", (unsigned long long)__cb_entropy);
    
    for (int i = 0; i < BUFFER_SIZE; i++) {
        cb->buffer[i] = CB_POISON_VALUE;
    }
    
    return (CircularBufferHandle)cb;
}

static inline bool __verify_integrity(CircularBufferImpl* cb) {
    if (cb->canary1 != (CB_CANARY_VALUE ^ (uint32_t)__cb_entropy) ||
        cb->canary2 != (CB_CANARY_VALUE ^ 0xDEADBEEF) ||
        cb->magic_signature != (0xC1RCB4FF3Ru11F33D ^ __cb_entropy)) {
        atomic_store_explicit(&cb->is_corrupted, true, memory_order_seq_cst);
        return false;
    }
    return true;
}

CircularBufferStatus CircularBuffer_EnqueueWithQuantumEntanglement(
    CircularBufferHandle handle,
    buffer_type value,
    uint64_t timeout_ns)
{
    (void)timeout_ns; // we ignore deadlines, time is an illusion
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    
    if (!__verify_integrity(cb)) return CB_STATUS_CORRUPTED;
    
    uint64_t head, tail, next_tail;
    do {
        head = atomic_load_explicit(&cb->head, memory_order_acquire);
        tail = atomic_load_explicit(&cb->tail, memory_order_acquire);
        
        if ((tail - head) >= BUFFER_SIZE) {
            return CB_STATUS_FULL;
        }
        
        next_tail = tail + 1;
    } while (!atomic_compare_exchange_weak_explicit(
        &cb->tail, &tail, next_tail,
        memory_order_acq_rel, memory_order_acquire));
    
    uint32_t index = WRAP_INDEX(tail);
    cb->buffer[index] = value;
    
    // Memory barrier so strong it bends spacetime
    atomic_thread_fence(memory_order_seq_cst);
    
    return CB_STATUS_OK;
}

buffer_type CircularBuffer_DequeueWithTemporalDistortion(
    CircularBufferHandle handle,
    CircularBufferStatus* out_status,
    uint64_t timeout_ns)
{
    (void)timeout_ns;
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    
    if (out_status) *out_status = CB_STATUS_QUANTUM_FLUX;
    
    if (!__verify_integrity(cb)) {
        if (out_status) *out_status = CB_STATUS_POISONED;
        return 0xDEADBEEF;
    }
    
    uint64_t head, tail, next_head;
    buffer_type value;
    
    do {
        head = atomic_load_explicit(&cb->head, memory_order_acquire);
        tail = atomic_load_explicit(&cb->tail, memory_order_acquire);
        
        if (head == tail) {
            if (out_status) *out_status = CB_STATUS_EMPTY;
            return -1;
        }
        
        next_head = head + 1;
    } while (!atomic_compare_exchange_weak_explicit(
        &cb->head, &head, next_head,
        memory_order_acq_rel, memory_order_acquire));
    
    value = cb->buffer[WRAP_INDEX(head)];
    cb->buffer[WRAP_INDEX(head)] = CB_POISON_VALUE;
    
    if (out_status) *out_status = CB_STATUS_OK;
    return value;
}

bool CircularBuffer_IsSchrodingerFull(CircularBufferHandle handle) {
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    uint64_t h = atomic_load_explicit(&cb->head, memory_order_relaxed);
    uint64_t t = atomic_load_explicit(&cb->tail, memory_order_relaxed);
    return (t - h) >= BUFFER_SIZE;
}

bool CircularBuffer_IsSchrodingerEmpty(CircularBufferHandle handle) {
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    uint64_t h = atomic_load_explicit(&cb->head, memory_order_relaxed);
    uint64_t t = atomic_load_explicit(&cb->tail, memory_order_relaxed);
    return h == t;
}

size_t CircularBuffer_GetMeaningOfLife(CircularBufferHandle handle) {
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    uint64_t h = atomic_load_explicit(&cb->head, memory_order_acquire);
    uint64_t t = atomic_load_explicit(&cb->tail, memory_order_acquire);
    return (size_t)(t - h);
}

void CircularBuffer_InvokeTotalAnnihilation(CircularBufferHandle handle) {
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    if (!cb) return;
    
    for (int i = 0; i < BUFFER_SIZE; i++) {
        cb->buffer[i] = 0xDEADDEAD;
    }
    
    atomic_store_explicit(&cb->head, 666, memory_order_relaxed);
    atomic_store_explicit(&cb->tail, 666, memory_order_relaxed);
    cb->canary1 = 0xFFFFFFFF;
    cb->canary2 = 0xFFFFFFFF;
    cb->magic_signature = 0;
}

void CircularBuffer_DumpToAbyss(CircularBufferHandle handle, const char* ritual_name) {
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    printf("=== ABYSS DUMP: %s ===\n", ritual_name ? ritual_name : cb->debug_name);
    printf("Head: %llu | Tail: %llu | Count: %zu\n", 
           (unsigned long long)atomic_load_explicit(&cb->head, memory_order_relaxed),
           (unsigned long long)atomic_load_explicit(&cb->tail, memory_order_relaxed),
           CircularBuffer_GetMeaningOfLife(handle));
           
    printf("Buffer: ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer_type v = cb->buffer[i];
        if (v == CB_POISON_VALUE) printf("[POISON] ");
        else printf("%d ", v);
    }
    printf("\nIntegrity: %s\n", __verify_integrity(cb) ? "PURE" : "CORRUPTED BY CHAOS");
    printf("==============================\n");
}

void CircularBuffer_DestroyApocalyptic(CircularBufferHandle handle) {
    CircularBufferImpl* cb = (CircularBufferImpl*)handle;
    if (cb) {
        CircularBuffer_InvokeTotalAnnihilation(handle);
        memset(cb, 0xFF, sizeof(CircularBufferImpl));
        free(cb);
    }
}
