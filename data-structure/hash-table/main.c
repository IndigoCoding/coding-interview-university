#include "hash-table.h"
#include <stdio.h>

int main() {
    HashTable* ht = htInit(0);
    htInsert(&ht, 10, 10);
    htInsert(&ht, 12, 12);
    htInsert(&ht, 14, 14);
    htInsert(&ht, 16, 16);
    htInsert(&ht, 18, 18);
    htInsert(&ht, 34, 34);
    htPrintInfo(ht);
    printf("Search for %d: %d\n", 34, htSearch(ht, 34));
    htDelete(&ht, 18);
    htDelete(&ht, 14);
    htPrintInfo(ht);
    htFree(ht);
}