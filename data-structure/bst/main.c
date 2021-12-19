#include "bst.h"
#include <stdio.h>
#include <stdint.h>

int main() {
    Node* n = NULL;
    bstInsert(&n, 10);
    bstInsert(&n, 15);
    bstInsert(&n, 8);
    bstInsert(&n, 9);
    bstInsert(&n, 5);
    bstInsert(&n, 20);
    bstInsert(&n, 14);
    bstInsert(&n, 21);
    dfs_inorder(n); puts("");
    bfs(n); puts("");
    printf("Search for 14 result: %ld\n", (intptr_t)bstSearch(n, 14));
    printf("Search for 16 result: %ld\n", (intptr_t)bstSearch(n, 16));
    printf("Height: %d\n", bstHeight(n));
    printf("Min: %d\n", bstMin(n));
    printf("Max: %d\n", bstMax(n));
    printf("Is BST: %d\n", isBst(n));
    printf("Inorder successor of 14: %ld\n", bstInorderSuccessor(n, 14) != NULL ? bstInorderSuccessor(n, 14)->value : UNDEFINED);
    bstFree(n);
}