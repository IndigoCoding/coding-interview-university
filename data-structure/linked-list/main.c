#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a[] = {1, 2, 3, 4};
    node* n = initFromArray(a, sizeof(a) / sizeof(int));
    insert(&n, 0, 10);
    insert(&n, 3, 20);
    insert(&n, 6, 30);
    erase(&n, 3);
    // reverse(&n);
    removeValue(&n, 20);
    printf("%d\n%d\n%d\n%d\n", size(n), at(n, 0), at(n, 3), at(n, 5));
    nodeFree(n);
}