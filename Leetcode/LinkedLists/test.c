#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    n = 5;
    int arr[5] = {1,2,3,4,5};
    int new_size = n - 1;
    int *copy = (int*)malloc(n * sizeof(int));

    int *ptr = copy;
    int new = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != 3){
            *copy++ = arr[i];
        }
        // else {
        //     *ptr++ = NULL;
        // }
    }
    for (int i = 0; i < new_size; i++){
        printf("%d ", copy[i]);
    }
}