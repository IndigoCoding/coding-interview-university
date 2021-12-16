#include "hash-table.h"
#include <stdio.h>
#include <stdlib.h>

float htLoadFactor(HashTable*);
void htRebuild(HashTable**, int);

HashTable* htInit(int size) {
    int i;
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    size = size ?: INITSIZE;
    ht->size = size;
    ht->entries = 0;
    ht->arr = (dict*)malloc(sizeof(dict) * size);
    for (i = 0; i < ht->size; i++) {
        ht->arr[i].key = UNDEFINED;
    }
    return ht;
}

int hash(int k, int m) {
    return k % m;
}

float htLoadFactor(HashTable* ht) {
    return (float)ht->entries / ht->size;
}

void htRebuild(HashTable** ht, int direction) {
    int i;
    HashTable* newHt = htInit(direction ? (*ht)->size * 2 : (*ht)->size / 2);
    for(i = 0; i < (*ht)->size; i++) {
        if(htExists(*ht, i)) {
            htInsert(&newHt, (*ht)->arr[i].key, (*ht)->arr[i].value);
        }
    }
    htFree(*ht);
    *ht = newHt;
}

void htInsert(HashTable** ht, int key, int value) {
    // table doubling strategy
    if (htLoadFactor(*ht) >= 0.5) {
        htRebuild(ht, HT_INCREASE);
    }
    int k = hash(key, (*ht)->size);
    // linear probing
    while(htExists(*ht, k)) {
        k = (k + 1) % (*ht)->size;
    }
    (*ht)->arr[k].value = value;
    (*ht)->arr[k].key = key;
    (*ht)->entries++;
}

_Bool htExists(HashTable* ht, int index) {
    return ht->arr[index].key != UNDEFINED;
}

int htSearch(HashTable* ht, int key) {
    int k = hash(key, ht->size);
    while(htExists(ht, k)) {
        if (ht->arr[k].key == key) {
            return ht->arr[k].value;
        }
        k = (k + 1) % ht->size;
    }
    return UNDEFINED;
}

void htDelete(HashTable** ht, int key) {
    int k = hash(key, (*ht)->size);
    int foundIndex;
    // linear probing
    while(htExists(*ht, k)) {
        if ((*ht)->arr[k].key == key) {
            (*ht)->arr[k].key = UNDEFINED;
            foundIndex = k;
            k = (k + 1) % (*ht)->size;
            // check from k+1 mod m until find a key or meet an empty slot
            while(htExists(*ht, k)) {
                if (hash((*ht)->arr[k].key, (*ht)->size) == foundIndex) {
                    (*ht)->arr[foundIndex].key = (*ht)->arr[k].key;
                    (*ht)->arr[foundIndex].value = (*ht)->arr[k].value;
                    (*ht)->arr[k].key = UNDEFINED;
                    break;
                }
                k = (k + 1) % (*ht)->size;
            }
            break;
        } else {
            k = (k + 1) % (*ht)->size;
        }
    }
    (*ht)->entries--;

    // table doubling strategy
    if (htLoadFactor(*ht) <= 0.25) {
        htRebuild(ht, HT_DECREASE);
    }
    return;
}

void htFree(HashTable* ht) {
    free(ht->arr);
    free(ht);
}

void htPrintInfo(HashTable* ht) {
    printf("Size: %d\n", ht->size);
    printf("Number of entries: %d\n", ht->entries);
    int i;
    for (i = 0; i < ht->size; i++) {
        if (htExists(ht, i)) {
            printf("Entry: %d, key: %d, value: %d\n", i, ht->arr[i].key, ht->arr[i].value);
        }
    }
}