#include <stdio.h>

int factorial(int n){
    if (n==0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int k = 5;
    int ret = factorial(k);
    printf("%d", ret);
}