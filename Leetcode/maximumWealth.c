#include <stdio.h>

// print array using size

int *sum(int a, int b, int*add){
    *add = a + b;
    return add;
}

int main(){
    int a = 1;
    int b = 2;
    int add;
    int *pAdd = sum(a, b, &add);
    printf("%d", *pAdd);

}