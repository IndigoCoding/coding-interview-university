#include "bst.h"
#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

void bstInsert(Node** n, int value) {
    if (*n == NULL) {
        *n = (Node*)malloc(sizeof(Node));
        (*n)->value = value;
        return;
    }
    if (value < (*n)->value) return bstInsert(&((*n)->left), value);
    else return bstInsert(&((*n)->right), value);
}

void bstFree(Node* n) {
    if (n == NULL) return;
    bstFree(n->left);
    bstFree(n->right);
    free(n);
}

void bfs(Node* n) {
    if (n == NULL) return;
    CircularBuffer* cb = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    cbEnqueue(cb, (intptr_t)n);
    while (!cbEmpty(cb)) {
        Node* cur = (Node*)cbDequeue(cb);
        printf("%d ", cur->value);
        if (cur->left != NULL) cbEnqueue(cb, (intptr_t)cur->left);
        if (cur->right != NULL) cbEnqueue(cb, (intptr_t)cur->right);
    }
}

void dfs_inorder(Node* n) {
    if (n == NULL) return;
    dfs_inorder(n->left);
    printf("%d ", n->value);
    dfs_inorder(n->right);
}

void dfs_preorder(Node* n) {
    if (n == NULL) return;
    printf("%d ", n->value);
    dfs_inorder(n->left);
    dfs_inorder(n->right);
}

void dfs_postorder(Node* n) {
    if (n == NULL) return;
    dfs_inorder(n->left);
    dfs_inorder(n->right);
    printf("%d ", n->value);
}

Node* bstSearch(Node* n, int value) {
    if (n == NULL) return NULL;
    if (n->value == value) return n;
    if (n->value < value) return bstSearch(n->right, value);
    else return bstSearch(n->left, value);
}

int bstHeight(Node* n) {
    if (n == NULL) return -1;
    return max(bstHeight(n->left), bstHeight(n->right)) + 1;
}

int bstMin(Node* n) {
    if (n->left == NULL) return n->value;
    return bstMin(n->left);
}

int bstMax(Node* n) {
    if (n->right == NULL) return n->value;
    return bstMax(n->right);
}

_Bool isBstUtil(Node* n, int minVal, int maxVal) {
    if (n == NULL) return 1;
    if (n->value > minVal && n->value < maxVal
    && isBstUtil(n->left, minVal, n->value)
    && isBstUtil(n->right, n->value, maxVal)) {
        return 1;
    } else {
        return 0;
    }
}

_Bool isBst(Node* n) {
    return isBstUtil(n, INT_MIN, INT_MAX);
}

Node* bstInorderSuccessor(Node* n, int value) {
    // traverse to node
    if (n == NULL) return NULL;
    Node* root = n;
    while (n->value != value) {
        if (n->value < value) n = n->right;
        else n = n->left;
    }
    // case 1: have right subtree -> find leftmost of the right subtree
    if (n->right != NULL) {
        n = n->right;
        while (n->left != NULL) n = n->left;
        return n;
    }
    // case 2: not have right subtree -> find the nearest ancestor where n is n its left subtree
    else {
        Node* successor = NULL;
        Node* ancestor = root;
        while (ancestor->value != n->value) {
            if (n->value < ancestor->value) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}