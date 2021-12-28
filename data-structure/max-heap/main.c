#include "max-heap.h"
#include <stdio.h>

void testHeap();
void testHeapSort();

int main() {
    // testHeap();
    testHeapSort();
}

void testHeap() {
    MaxHeap* mh = mhInit();
    mhInsert(mh, 10);
    mhInsert(mh, 14);
    mhInsert(mh, 9);
    mhInsert(mh, 11);
    mhInsert(mh, 5);
    mhInsert(mh, 16);
    mhInsert(mh, 2);
    mhInsert(mh, 3);
    mhInsert(mh, 15);
    mhPrintInfo(mh);
    printf("Extract max: %d\n", mhExtractMax(mh));
    mhPrintInfo(mh);
    printf("Remove: %d\n", mhRemove(mh, 3));
    mhPrintInfo(mh);
}

void testHeapSort() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]), i;
    heapSort(arr, size);
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}