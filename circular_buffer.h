#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

#define BUFFER_SIZE 10

typedef int buffer_type;

typedef struct {
    buffer_type buffer[BUFFER_SIZE];
    buffer_type *glava; // mesto odakle citamo
    buffer_type *rep;   // mesto gde pisemo
} CircularBuffer;

// funkcije, sve rade sa pointerom da ne kopiramo strukturu
void CircularInit(CircularBuffer *cb);
bool CircularIsFull(const CircularBuffer *cb);
bool CircularIsEmpty(const CircularBuffer *cb);
void CircularPush(CircularBuffer *cb, buffer_type vr);
buffer_type CircularPop(CircularBuffer *cb);
void CircularEmptyBuff(CircularBuffer *cb);
void CircularDump(const CircularBuffer *cb);

#endif





