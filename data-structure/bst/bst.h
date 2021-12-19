#include "../queue/fifo.h"
#include <limits.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void bstInsert(Node**, int);
void bstFree(Node*);
void bfs(Node*);
void dfs_inorder(Node*);
void dfs_preorder(Node*);
void dfs_postorder(Node*);
Node* bstSearch(Node*, int);
int bstHeight(Node*);
int bstMin(Node*);
int bstMax(Node*);
_Bool isBst(Node*);
Node* bstInorderSuccessor(Node*, int);