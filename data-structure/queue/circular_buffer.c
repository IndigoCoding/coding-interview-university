#include "fifo.h"
#include <stdio.h>

_Bool cbEmpty(CircularBuffer* cb) {
    return cb->start == cb->end;
}

_Bool cbFull(CircularBuffer* cb) {
    return (cb->end - cb->start +1) % MAX_CIRCULAR_LENGTH == 0;
}

void cbEnqueue(CircularBuffer* cb, intptr_t value) {
    if (cbFull(cb)) {
        return;
    }
    cb->buffer[cb->end] = value;
    cb->end = (cb->end + 1) % MAX_CIRCULAR_LENGTH;
}

intptr_t cbDequeue(CircularBuffer* cb) {
    if (cbEmpty(cb)) {
        return UNDEFINED;
    }
    intptr_t value = cb->buffer[cb->start];
    cb->start = (cb->start + 1) % MAX_CIRCULAR_LENGTH;
    return value;
}

void cbPrintInfo(CircularBuffer* cb) {
    printf("Start: %d, End: %d\n", cb->start, cb->end);
    printf("Buffer info: \n");
    if(cbEmpty(cb)) printf("EMPTY\n");
    int i = 0;
    while (cb->start + i < cb->end || (cb->end < cb->start && cb->start + i < cb->end + MAX_CIRCULAR_LENGTH)) {
        printf("Index: %d, value: %ld\n", (cb->start + i) % MAX_CIRCULAR_LENGTH, cb->buffer[(cb->start + i) % MAX_CIRCULAR_LENGTH]);
        i++;
    }
}