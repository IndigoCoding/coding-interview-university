#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dynamicEdit(char*, char*, int, int);
int min3(int, int, int);

enum operation{MATCH, INSERT, DELETE};

int main(){
    char* s = "photograph";
    char* t = "tomography";
    printf("\n%d\n", dynamicEdit(s, t, strlen(s), strlen(t)));
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
        puts("");
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