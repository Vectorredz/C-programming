#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *b; // temp  = 10
    *b = *a; // b = 5
    *a = temp; // a = 10
}

int main(){
    int a, b;
    int *pa = &a;
    int *pb = &b;
    a = 5;
    b = 10;
    printf("value of a = %d value of b = %d", *pa, *pb); 
    swap(pa, pb);
    printf("value of a = %d value of b = %d", *pa, *pb); 

}

