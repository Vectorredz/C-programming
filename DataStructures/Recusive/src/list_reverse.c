#include <stdio.h>

//reversing list: [1,2,3] -> [3,2,1]

void copy_array(int *source, int *copy, int len){
    for (int i = 0; i < len; i++){
        copy[i] = source[i];
    }
}

void reverse(int *elems, int len, int *orig){
    if (len == 0){
        return;
    }
    else {
        elems[0] = orig[len-1];
        return reverse(elems + 1, len-1, orig); 
    }
}

int main(){
    int arr[] = {1,2,3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int orig[len];
    copy_array(arr, orig, len);
    reverse(arr, len, orig);
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    


}