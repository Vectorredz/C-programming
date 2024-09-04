// { 12, 16, 20, 40, 50, 70 }

#include <stdio.h>

void insert(int arr[], int elem, int len);

int main(){
    int arr[] = { 12, 16, 20, 40, 50, 70 };
    int elem = 26;
    int len = sizeof(arr) / sizeof(arr[0]);
    insert(arr, elem, len);
    for (int i = 0; i <= len; i++ ){
        printf("%d ", arr[i]);
    }

}

void insert(int arr[], int elem, int len) {
    for (int i = 0; i < (len+1); i++){
        if (i = (len)){
            arr[i] = elem;
        }

    }
}