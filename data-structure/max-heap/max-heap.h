#define MAX_ARR 1000

typedef struct MaxHeap {
    int* arr;
    int size;
} MaxHeap;

MaxHeap* mhInit();
int mhSize(MaxHeap*);
void mhInsert(MaxHeap*, int);
void mhPrintInfo(MaxHeap*);
int mhGetMax(MaxHeap*);
_Bool mhIsEmpty(MaxHeap*);
int mhExtractMax(MaxHeap*);
int mhRemove(MaxHeap*, int);
void heapSort(int*, int);