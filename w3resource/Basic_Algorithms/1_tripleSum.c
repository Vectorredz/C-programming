#include <stdio.h>

int tripleSum(int x, int y, int *ret){
    int sum = x + y;
    if (x == y){
        sum = sum * 3;
        *ret = sum;
    }
    *ret = sum;

}

int main(){
    int x, y;
    int ret;
    
    printf("Enter first value: ");
    scanf("%d", &x);
    printf("Enter second value: ");
    scanf("%d", &y);

    tripleSum(x, y, &ret);
    printf("%d", ret);
}