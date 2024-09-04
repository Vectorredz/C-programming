#include <stdio.h>

int test(int arr[], int len);

int main(){
    int array1[] = {10, 20, 30, 40, 50};
    int len1 = sizeof(array1) / sizeof(array1[0]);
    int array2[] = {10, 20, -30, -40, 50};
    int len2 = sizeof(array2) / sizeof(array2[0]);
    printf("%d", test(array1, len1));
    printf("\n%d", test(array2, len2));
}

int test(int arr[], int len){
    int lens = len;
    int sum = 0;
    for (int i = 0; i < lens; i++){  
        sum += arr[i];
    }

    return sum;
}