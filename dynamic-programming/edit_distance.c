#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit_distance.h"

int EditDistance(char* s, char* t){
    int i, j, k, opts[3];
    int initialSize = (strlen(s) <= strlen(t)) ? strlen(s) : strlen(t);
    cell** table;
    table = (cell**)malloc(sizeof(cell) * (initialSize + 1));
    for(i = 0; i <= initialSize; i++){
        table[i] = (cell*)malloc(sizeof(cell) * (initialSize + 1));
    }
    for(i = 0; i <= initialSize; i++){
        rowInit(table, i);
        columnInit(table, i);
    }

    for(i = 1; i <= strlen(s); i++){
        for(j = 1; j <= strlen(t); j++){
            opts[MATCH] = table[i - 1][j - 1].cost + match(s[i - 1], t[j - 1]);
            opts[INSERT] = table[i][j - 1].cost + indel(t[j - 1]);
            opts[DELETE] = table[i - 1][j].cost + indel(s[i - 1]);

            table[i][j].cost = opts[MATCH];
            table[i][j].parent = MATCH;
            for(k = INSERT; k <= DELETE; k++){
                if(opts[k] < table[i][j].cost){
                    table[i][j].cost = opts[k];
                    table[i][j].parent = k;
                }
            }
        }
    }

    for(i = 0; i <= strlen(s); i++){
        for(j = 0; j <= strlen(t); j++){
            printf("%5d", table[i][j].parent);
        }
        puts("");
    }
    goalCell(s, t, &i, &j);
    k = table[i][j].cost;

    reconstructPath(table, s, t, i, j);
    puts("");
    for(i = 0; i <= initialSize; i++){
        free(table[i]);
    }
    free(table);
    return k;
}

void rowInit(cell** table, int i){
    table[0][i].cost = i;
    if(i > 0){
        table[0][i].parent = INSERT;
    } else {
        table[0][i].parent = -1;
    }
}

void columnInit(cell** table, int i){
    table[i][0].cost = i;
    if(i > 0){
        table[i][0].parent = DELETE;
    } else {
        table[i][0].parent = -1;
    }
}

int match(char a, char b){
    if(a == b){
        return 0;
    } else {
        return 1;
    }
}

int indel(char a){
    return 1;
}

void goalCell(char* s, char* t, int* i, int* j){
    *i = strlen(s);
    *j = strlen(t);
}

void reconstructPath(cell** table, char* s, char* t, int i, int j){
    int parent = table[i][j].parent;
    if(parent == -1) return;
    if(parent == MATCH){
        reconstructPath(table, s, t, i - 1, j - 1);
        matchOut(s, t, i, j);
    } else if(parent == INSERT){
        reconstructPath(table, s, t, i, j - 1);
        insertOut(t, j);
    } else {
        reconstructPath(table, s, t, i - 1, j);
        deleteOut(s, i);
    }
    return;
}

void matchOut(char* s, char* t, int i, int j){
    printf("%s", s[i - 1] == t[j - 1] ? "M" : "S");
}

void insertOut(char* t, int j){
    printf("I");
}

void deleteOut(char* s, int i){
    printf("D");
}