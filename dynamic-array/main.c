#include "vector.h"
#include <stdio.h>

int main()
{
    vector v;
    int i;
    initVector(&v);
    v.push(&v, 1);
    v.push(&v, 3);
    v.push(&v, 1);
    v.insert(&v, 2, 10);
    v.prepend(&v, 100);
    v.removeV(&v, 1);
    for (i = 0; i < v.size(&v); i++) {
        printf("%d\n", v.at(&v, i));
    }
    return 0;
}