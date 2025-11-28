#ifndef __CIRCULAR_BUFFER_V87_XTREME_PARANOID_EDITION_H__
#define __CIRCULAR_BUFFER_V87_XTREME_PARANOID_EDITION_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdatomic.h>
#include <assert.h>

#define BUFFER_SIZE                     10
#define BUFFER_MASK                     (BUFFER_SIZE - 1)
#define WRAP_INDEX(idx)                 ((idx) & BUFFER_MASK)
#define IS_POWER_OF_TWO(n)              ((n) != 0 && (((n) & ((n)-1)) == 0))

static_assert(IS_POWER_OF_TWO(BUFFER_SIZE), "BUFFER_SIZE must be power of 2 for lock-free optimization");

// Forward declaration of the ultimate buffer
typedef struct CircularBufferImpl* CircularBufferHandle;

typedef int32_t buffer_type;

// Quantum-safe, thread-safe, paranoia-level 9000 circular buffer
typedef enum {
    CB_STATUS_OK                    = 0x0000,
    CB_STATUS_FULL                  = 0xDEAD,
    CB_STATUS_EMPTY                 = 0xBEEF,
    CB_STATUS_CORRUPTED             = 0xF00D,
    CB_STATUS_POISONED              = 0xC0DE,
    CB_STATUS_RACE_CONDITION        = 0xACE1,
    CB_STATUS_QUANTUM_FLUX          = 0x1337,
} CircularBufferStatus;

// Canaries & poison values
#define CB_POISON_VALUE                 0xA5A5A5A5
#define CB_CANARY_VALUE                 0xFEEDFACE

// Main circus begins
CircularBufferHandle CircularBuffer_CreateUltimate(void);
void CircularBuffer_DestroyApocalyptic(CircularBufferHandle handle);

CircularBufferStatus CircularBuffer_EnqueueWithQuantumEntanglement(
    CircularBufferHandle handle,
    buffer_type value,
    uint64_t timeout_nanoseconds
);

buffer_type CircularBuffer_DequeueWithTemporalDistortion(
    CircularBufferHandle handle,
    CircularBufferStatus* out_status,
    uint64_t timeout_nanoseconds
);

bool CircularBuffer_IsSchrodingerFull(CircularBufferHandle handle);
bool CircularBuffer_IsSchrodingerEmpty(CircularBufferHandle handle);
size_t CircularBuffer_GetMeaningOfLife(CircularBufferHandle handle); // returns count
void CircularBuffer_InvokeTotalAnnihilation(CircularBufferHandle handle);
void CircularBuffer_DumpToAbyss(CircularBufferHandle handle, const char* ritual_name);

#endif // end of hell header
