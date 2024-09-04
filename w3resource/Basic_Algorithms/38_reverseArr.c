#include <stdio.h>



int main(){
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = len-1; i >= 0; i--){
        arr[i] = arr[len-1];
    }
    for (int j = 0; j < len; j++){
        printf("%d", arr[j]);
    }

}