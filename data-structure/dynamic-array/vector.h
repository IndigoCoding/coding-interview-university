#define INIT_SIZE 2

typedef struct vectorList{
    int* data;
    int capacity;
    int size;
} vectorList;

typedef struct vector{
    vectorList list;
    int (*size)(struct vector *);
    int (*capacity)(struct vector *);
    _Bool (*isEmpty)(struct vector *);
    int (*at)(struct vector *, int index);
    void (*push)(struct vector *, int value);
    int (*pop)(struct vector *);
    void (*insert)(struct vector *, int index, int value);
    void (*prepend)(struct vector *, int value);
    void (*delete)(struct vector *, int index);
    void (*removeV)(struct vector *, int value);
    int (*find)(struct vector *, int value);
    void (*resize)(struct vector *, int newCapacity);
} vector;

void initVector(vector *);
int size(vector *);
int capacity(vector *);
_Bool isEmpty(vector *);
int at(vector *, int);
void push(vector *, int);
int pop(vector *);
void insert(vector *, int, int);
void prepend(vector *, int);
void delete(vector *, int);
void removeV(vector *, int);
int find(vector *, int);
void resize(vector *, int);