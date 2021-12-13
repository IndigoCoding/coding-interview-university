#include "vector.h"
#include <stdlib.h>

#define UNDEFINED -2147483648
#define NOT_FOUND -1

void initVector(vector* v)
{
    v->list.capacity = INIT_SIZE;
    v->list.size = 0;
    v->list.data = (int*)malloc(sizeof(int) * INIT_SIZE);
    v->size = size;
    v->capacity = capacity;
    v->isEmpty = isEmpty;
    v->at = at;
    v->push = push;
    v->pop = pop;
    v->insert = insert;
    v->prepend = prepend;
    v->delete = delete;
    v->removeV = removeV;
    v->find = find;
    v->resize = resize;
}

int size(vector* v)
{
    return v->list.size;
}

int capacity(vector* v)
{
    return v->list.capacity;
}

_Bool isEmpty(vector* v)
{
    return v->size(v) == 0;
}

int at(vector* v, int index)
{
    if (index >= v->size(v) || index < 0) {
        return UNDEFINED;
    }
    return *(v->list.data + index);
}

void push(vector * v, int value)
{
    if (v->capacity(v) == v->size(v)) {
        v->resize(v, v->capacity(v) * 2);
    }
    *(v->list.data + v->size(v)) = value;
    v->list.size++;
}

int pop(vector *v)
{
    if (v->isEmpty(v)) {
        return UNDEFINED;
    }
    if ((float)(v->size(v) - 1) / (float)(v->capacity(v)) <= 0.25) {
        v->resize(v, v->capacity(v) / 2);
    }
    v->list.size--;
    return v->at(v, v->size(v));
}

void insert(vector *v, int index, int value)
{
    int size = v->size(v);
    if (index > size || index < 0) {
        return;
    }

    if (v->capacity(v) == v->size(v)) {
        v->resize(v, v->capacity(v) * 2);
    }

    if (index == size) {
        return v->push(v, value);
    }

    while (1) {
        *(v->list.data + size) = *(v->list.data + size - 1);
        size --;
        if (size == index) {
            break;
        }
    }
    *(v->list.data + index) = value;
    v->list.size++;
}

void prepend(vector * v, int value)
{
    v->insert(v, 0, value);
}

void delete(vector * v, int index)
{
    int size = v->size(v);

    if (index >= size || index < 0) {
        return;
    }

    while (1) {
        *(v->list.data + index) = *(v->list.data + index + 1);
        index++;
        if (size == index) {
            break;
        }
    }

    if ((float)(v->size(v) - 1) / (float)(v->capacity(v)) <= 0.25) {
        v->resize(v, v->capacity(v) / 2);
    }

    v->list.size--;
}

void removeV(vector *v, int value)
{
    int index;
    if ((index = v->find(v, value)) >= 0) {
        v->delete(v, index);
        v->removeV(v, value);
    }
}

int find(vector *v, int value)
{
    int index = 0;
    while (*(v->list.data + (index++)) != value && index <= v->size(v));
    return index <= v->size(v) ? index - 1 : NOT_FOUND;
}

void resize(vector *v, int newCapacity) 
{
    int* newData = (int *)malloc(sizeof(int) * newCapacity);
    int index = 0;
    while ((*newData++ = v->at(v, index++)) != UNDEFINED);
    free(v->list.data);
    v->list.data = (newData-=index);
}