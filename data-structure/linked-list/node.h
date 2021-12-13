#define UNDEFINED -2147483648
#define NOT_FOUND -1

typedef struct node {
    struct node* next;
    int value;
} node;

node* initFromArray(int[], int);
int size(node*);
void nodeFree(node*);
int at(node*, int);
void pushFront(node**, int);
int popFront(node**);
void pushBack(node*, int);
int popBack(node*);
int front(node*);
int back(node*);
void insert(node**, int, int);
void erase(node**, int);
void reverse(node**);
void removeValue(node**, int);