#include "../linked-list/node.h"
#define MAX_CIRCULAR_LENGTH 5

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
    int buffer[MAX_CIRCULAR_LENGTH];
    int start;
    int end;
} CircularBuffer;

void cbEnqueue(CircularBuffer*, int);
int cbDequeue(CircularBuffer*);
_Bool cbEmpty(CircularBuffer*);
_Bool cbFull(CircularBuffer*);
void cbPrintInfo(CircularBuffer*);