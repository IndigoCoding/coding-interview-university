#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int naiveFib(int);
int dynamicFib(int);

int main(){
    clock_t begin = clock();
    printf("%d\n", naiveFib(44));
    clock_t end = clock();
    printf("Naive fibo takes %.4f time\n", (double)(end - begin));
    begin = clock();
    printf("%d\n", dynamicFib(45));
    end = clock();
    printf("Dynamic fibo takes %.4f time\n", (double)(end - begin));
    return 0;
}

int naiveFib(int n){
    if(n < 2){
        return 1;
    } else{
        return naiveFib(n-1) + naiveFib(n-2);
    }
}

int dynamicFib(int n){
    int* a;
    int i, ret;

    a = (int*) malloc(sizeof(a) * n);
    for(i = 0; i < n; i++){
        if(i < 2){
            a[i] = 1;
        } else {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    ret = a[n - 1];
    free(a);
    return ret;
}