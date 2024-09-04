#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr1[4] = {1,3,5,7}; // &(arr[0])
    int arr2[4] = {2,4,6,8};

    int *ptr = arr1;
    for (int i = 0; i < 4; i++){
        printf("%d ", *ptr++);
    }

}
