#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int naiveEdit(char*, char*, int, int);
int dynamicEdit(char*, char*, int, int);
int min(int, int, int);

enum operation{MATCH, INSERT, DELETE};

int main(){
    char s[] = "you should not";
    char t[] = "thou shalt not";
    time_t begin = clock();
    printf("%d\n", naiveEdit(s, t, strlen(s), strlen(t)));
    time_t end = clock();
    printf("Naive edit distance takes %.4f millisecs\n", (double)(end - begin));
    begin = clock();
    printf("%d\n", dynamicEdit(s, t, strlen(s), strlen(t)));
    end = clock();
    printf("Dynamic edit distance takes %.4f millisecs\n", (double)(end - begin));
    return 0;
}

int naiveEdit(char* s, char* t, int i, int j){
    int k, opts[3];
    int minEditDistance;

    if(i == 0) return j;
    if(j == 0) return i;

    opts[MATCH] = naiveEdit(s, t, i - 1, j - 1) + (s[i - 1] == t[j - 1] ? 0 : 1);
    opts[INSERT] = naiveEdit(s, t, i - 1, j) + 1;
    opts[DELETE] = naiveEdit(s, t, i, j - 1) + 1;

    minEditDistance = opts[MATCH];
    for(k = INSERT; k <= DELETE; k++){
        minEditDistance = (opts[k] <= minEditDistance ? opts[k] : minEditDistance);
    }
    
    return minEditDistance;
}

int dynamicEdit(char* s, char* t, int i, int j){
    int table[i + 1][j + 1];
    int m, n;
    for(m = 0; m <= i; m++){
        for(n = 0; n <= j; n++){
            if(m == 0){
                table[m][n] = n;
            } else if(n == 0){
                table[m][n] = m;
            } else if(s[m - 1] == t[n - 1]){
                table[m][n] = table[m - 1][n - 1];
            } else {
                table[m][n] = 1 + min(table[m - 1][n - 1], table[m - 1][n], table[m][n - 1]);
            }
        }
    }
    return table[i][j];
}

int min(int a, int b, int c){
    return (a <= b && a <=c) ? a : (b <= c && b <= a) ? b : c;
}