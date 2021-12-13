#include "node.h"
#include <stdlib.h>

node* initFromArray(int a[], int size){
    node* n = (node *)malloc(sizeof(node));
    node* cur = n;
    int i;
    for (i = 0; i < size; i++) {
        cur->value = a[i];
        if (i < (size - 1)) {
            cur->next = (node *)malloc(sizeof(node));
            cur = cur->next;
        } else {
            cur->next = NULL;
        }
    }
    return n;
}

int size(node* n){
    int i;
    for (i = 1; n->next != NULL; i++) {
        n = n->next;
    }
    return i;
}

void nodeFree(node* n) {
    if (n->next != NULL) {
        nodeFree(n->next);
    }
    free(n);
}

int at(node* n, int index) {
    int i = 0;
    do {
        if (i++ == index) return n->value;
        n = n->next;
    } while (n->next != NULL);
    if (i == index) return n->value;
    return UNDEFINED;
}

void pushFront(node** n, int value) {
    node* newRoot = (node*)malloc(sizeof(node));
    newRoot->value = value;
    newRoot->next = *n;
    *n = newRoot;
}

int popFront(node** n) {
    int val = (*n)->value;
    node* v = *n;
    *n = (*n)->next;
    free(v);
    return val;
}

void pushBack(node* n, int value) {
    while (n->next != NULL) {
        n = n->next;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    n->next = newNode;
}

int popBack(node* n) {
    node* newBack = n;
    while (n->next != NULL) {
        newBack = n;
        n = n->next;
    }
    int val = n->value;
    free(n);
    newBack->next = NULL;
    return val;
}

int front(node* n) {
    return n->value;
}

int back(node* n) {
    while(n->next != NULL) {
        n = n->next;
    }
    return n->value;
}

void insert(node** n, int index, int value) {
    if (index == 0) {
        return pushFront(n, value);
    }
    int i = 0, found = 0;
    node* cur = (*n);
    do {
        if (i++ == (index - 1)) {
            found = 1;
            break;
        } else {
            cur = cur->next;
        }
    } while (cur->next != NULL);
    if (found || (i == (index - 1))) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->value = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void erase(node** n, int index) {
    if (index == 0) {
        popFront(n);
        return;
    }
    int i = 0;
    node* cur = (*n);
    node* prev;
    do {
        if (i++ == index) {
           prev->next = cur->next;
           free(cur);
           return;
        } else {
            prev = cur;
            cur = cur->next;
        }
    } while (cur->next != NULL);
    if (i == index) {
        prev->next = NULL;
        free(cur);
    }
}

void reverse(node** n) {
    if ((*n)->next == NULL) return;
    node* sec = (*n)->next;
    node* lastNext = sec->next;
    sec->next = *n;
    (*n)->next = NULL;
    while (lastNext != NULL) {
        *n = sec;
        sec = lastNext;
        lastNext = sec->next;
        sec->next = *n;
    }
    *n = sec;
}

void removeValue(node** n, int value) {
    if ((*n)->value == value) {
        popFront(n);
        return;
    }
    node* cur = (*n);
    node* prev;
    do {
        if (cur->value == value) {
           prev->next = cur->next;
           free(cur);
           return;
        } else {
            prev = cur;
            cur = cur->next;
        }
    } while (cur->next != NULL);
    if (cur->value == value) {
        prev->next = NULL;
        free(cur);
    }
}