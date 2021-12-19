#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

void testCircularBuffer(void);
void testQueue(void);

int main () {
    testCircularBuffer();
    testQueue();
}

void testCircularBuffer() {
    printf("### TEST CIRCULAR BUFFER ###\n");
    CircularBuffer* cb = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    cbEnqueue(cb, 1);
    cbEnqueue(cb, 2);
    cbEnqueue(cb, 3);
    cbEnqueue(cb, 4);
    cbEnqueue(cb, 5);
    printf("Dequeue %ld\n", cbDequeue(cb));
    printf("Dequeue %ld\n", cbDequeue(cb));
    cbEnqueue(cb, 6);
    cbEnqueue(cb, 7);
    printf("Dequeue %ld\n", cbDequeue(cb));
    printf("Dequeue %ld\n", cbDequeue(cb));
    cbEnqueue(cb, 8);
    cbPrintInfo(cb);
    printf("######\n");
}

void testQueue() {
    printf("### TEST QUEUE ###\n");
    Queue* q = qInit();
    qEnqueue(q, 1);
    qEnqueue(q, 2);
    qEnqueue(q, 3);
    printf("Dequeue %d\n", qDequeue(q));
    printf("Dequeue %d\n", qDequeue(q));
    qEnqueue(q, 4);
    printf("Dequeue %d\n", qDequeue(q));
    qEnqueue(q, 5);
    qEnqueue(q, 6);
    qEnqueue(q, 7);
    printf("Dequeue %d\n", qDequeue(q));
    qPrintInfo(q);
    printf("######\n");
}
