#include <stdio.h>

int sequence(int arr[]){
    int len = sizeof(arr) / sizeof(arr[0]);
    return len;
}

int main(){
    int arr[] = {1,2,3,4};
    int ret = sequence(arr);
    printf("%d", ret);

}