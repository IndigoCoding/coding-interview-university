#include "max-heap.h"
#include <stdio.h>
#include <stdlib.h>

int parentIndex(int);
int leftIndex(int);
int rightIndex(int);
void siftUp(MaxHeap*, int);
void siftDown(MaxHeap*, int);
void swap(int*, int*);

MaxHeap* mhInit() {
    MaxHeap* mh = (MaxHeap*)malloc(sizeof(MaxHeap));
    mh->arr = (int*)malloc(sizeof(int) * MAX_ARR);
    return mh;
}

int mhSize(MaxHeap* mh) {
    return mh->size;
}

void mhInsert(MaxHeap* mh, int value) {
    mh->arr[mh->size] = value;
    siftUp(mh, mh->size);
    mh->size++;
}

void mhPrintInfo(MaxHeap* mh) {
    int i;
    for (i = 0; i < mhSize(mh); i++) {
        printf("%d\n", mh->arr[i]);
    }
}

int mhGetMax(MaxHeap* mh) {
    return mh->size ? mh->arr[0] : 0;
}

_Bool mhIsEmpty(MaxHeap* mh) {
    return mh->size ? 1 : 0;
}

int mhExtractMax(MaxHeap* mh) {
    return mhRemove(mh, 0);
}

int mhRemove(MaxHeap* mh, int index) {
    swap(mh->arr + index, mh->arr + mh->size - 1);
    mh->size--;
    siftDown(mh, index);
    return mh->arr[mh->size];
}

void heapSort(int* arr, int size) {
    MaxHeap* mh = mhInit();
    mh->arr = arr;
    mh->size = size;
    int i;
    // build max heap
    for (i = size - 1; i >= 0; i--) {
        if (leftIndex(i) >= size) continue;
        siftDown(mh, i);
    }

    for (i = size - 1; i >= 1; i--) {
        swap(mh->arr, mh->arr + i);
        mh->size--;
        siftDown(mh, 0);
    }
}

void siftUp(MaxHeap* mh, int index) {
    while (index) {
        if (mh->arr[parentIndex(index)] < mh->arr[index]) {
            swap(mh->arr + parentIndex(index), mh->arr + index);
            index = parentIndex(index);
        } else {
            break;
        }
    }
}

int parentIndex(int index) {
    return index % 2 == 0 ? index / 2 - 1 : index / 2;
}

int leftIndex(int index) {
    return index * 2 + 1;
}

int rightIndex(int index) {
    return index * 2 + 2;
}

void siftDown(MaxHeap* mh, int index) {
    int largest = index;
    if (mh->arr[leftIndex(index)] > mh->arr[index]) largest = leftIndex(index);
    if (mh->arr[rightIndex(index)] > mh->arr[largest]) largest = rightIndex(index);
    if (largest != index && largest < mh->size) {
        swap(mh->arr + index, mh->arr + largest);
        siftDown(mh, largest);
    }
}

void swap(int* a, int* b) {
    *a += *b;
    *b = (*a) - *b;
    *a -= *b;
}