#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

Queue* qInit() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = (node*)malloc(sizeof(node));
    q->tail = q->head;
    return q;
}

_Bool qEmpty(Queue* q) {
    return q->head == q->tail;
}

void qEnqueue(Queue* q, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    q->tail->next = newNode;
    q->tail = newNode;
}

int qDequeue(Queue* q) {
    if (!qEmpty(q)){
        return popFront(&q->head->next);
    } else {
        return UNDEFINED;
    }
}

void qPrintInfo(Queue* q) {
    printf("Queue Info: \n");
    node* cur = q->head->next;
    while (1) {
        printf("Value: %d\n", cur->value);
        cur = cur->next;
        if(cur == q->tail) {
            printf("Value: %d\n", cur->value);
            return;
        }
    }
}