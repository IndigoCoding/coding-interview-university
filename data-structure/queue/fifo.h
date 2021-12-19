#include "../linked-list/node.h"
#include <stdint.h>
#define MAX_CIRCULAR_LENGTH 16

typedef struct Queue {
    node* head;
    node* tail;
} Queue;

Queue* qInit();
void qEnqueue(Queue*, int);
int qDequeue(Queue*);
_Bool qEmpty(Queue*);
void qPrintInfo(Queue*);

typedef struct CircularBuffer {
    intptr_t buffer[MAX_CIRCULAR_LENGTH];
    int start;
    int end;
} CircularBuffer;

void cbEnqueue(CircularBuffer*, intptr_t);
intptr_t cbDequeue(CircularBuffer*);
_Bool cbEmpty(CircularBuffer*);
_Bool cbFull(CircularBuffer*);
void cbPrintInfo(CircularBuffer*);