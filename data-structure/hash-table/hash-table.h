#define UNDEFINED -2147483648
#define INITSIZE 8
#define HT_INCREASE 1
#define HT_DECREASE 0

typedef struct dict {
    int key;
    int value;
} dict;

typedef struct HashTable {
    struct dict* arr;
    int size;
    int entries;
} HashTable;

HashTable* htInit(int);
int hash(int, int);
void htInsert(HashTable**, int, int);
_Bool htExists(HashTable*, int);
int htSearch(HashTable*, int);
void htDelete(HashTable**, int);
void htFree(HashTable*);
void htPrintInfo(HashTable* ht);