#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dynamicEdit(char*, char*, int, int);
int min3(int, int, int);

enum operation{MATCH, INSERT, DELETE};

int main(){
    char* s[] = {"watch the movie raising arizona?", "this is what happens when I type slow", "leonard skiena"};
    char* t[] = {"watch da mets raze arizona?", "htishisth whaty havpens when ui type fasht", "lynard skynard"};
    printf("\n%d\n", dynamicEdit(s[0], t[0], strlen(s[0]), strlen(t[0])));
    printf("\n%d\n", dynamicEdit(s[1], t[1], strlen(s[1]), strlen(t[1])));
    printf("\n%d\n", dynamicEdit(s[2], t[2], strlen(s[2]), strlen(t[2])));
    return 0;
}

int dynamicEdit(char* s, char* t, int i, int j){
    int table[i + 1][j + 1];
    int m, n, min;
    for(m = 0; m <= i; m++){
        for(n = 0; n <= j; n++){
            if(m == 0){
                table[m][n] = n;
            } else if(n == 0){
                table[m][n] = m;
            } else if(s[m - 1] == t[n - 1]){ // case match
                table[m][n] = table[m - 1][n - 1];
            } else {
                table[m][n] = 1 + min3(table[m - 1][n - 1], table[m - 1][n], table[m][n - 1]);
            }
            printf("%5d", table[m][n]);
        }
        printf("\n");
    }

        // visualize the difference
    m = 0; n = 0;
    while(1){
        if(m == i && n == j) break;
        if(m == i && n < j){
            printf("D");
            n++;
        } else if (n == j && m < i){
            printf("I");
            m++;
        } else {
            min = min3(table[m + 1][n + 1], table[m][n + 1], table[m + 1][n]);
            if(min == table[m + 1][n + 1]){
                if(min != table[m][n]){
                    printf("S");
                } else {
                    printf("M");
                }
                m++; n++;
            } else if(min == table[m][n + 1]){
                printf("D");
                n++;
            } else {
                printf("I");
                m++;
            }
        }
    }
    return table[i][j];
}

int min3(int substitute, int delete, int insert){
    if(substitute <= delete && substitute <= insert){
        return substitute;
    } else if (delete <= substitute && substitute <= insert){
        return delete;
    } else {
        return insert;
    }
}