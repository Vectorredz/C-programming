// { 12, 34, 10, 6, 40 }
// elem = 40
#include <stdio.h>

int find_element(int arr[], int elem, int len);

int main(){
    int arr1[] = {12, 34, 10, 6, 40};
    int elem = 40;
    int len = sizeof(arr1) / sizeof(arr1[0]);
    printf("elem is at %d; index = %d ", find_element(arr1, elem, len), find_element(arr1, elem, len)-1);
}

int find_element(int arr[], int elem, int len){
    for (int i =  0; i < len; i++){
        if (arr[i] == elem){
            return i+1;
        }
    }
}

