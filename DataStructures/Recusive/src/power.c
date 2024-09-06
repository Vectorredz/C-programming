#include <stdio.h>

int power(int n, int x){
    if (x == 0){
        return 1;
    }
    else {
        return (n * power(n, x-1));
    }
}


int main(){
    int n = 5;
    int x = 2;
    int ret = power(n, x);
    printf("%d", ret);
    return 0;
}