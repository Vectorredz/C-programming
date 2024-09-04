#include <stdio.h>
int main(){
    int x;
    int y;
    int z;
    printf("Input the first integer: ", &x);
    scanf("%d", &x);
    printf("Input the second integer: ", &y);
    scanf("%d", &y);
    printf("Input the third integer: ", &z);
    scanf("%d", &z);

    int arr[] = {x, y, z};
    int ret = arr[0];
    int max;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i; i < len; i++){
        if (ret >= arr[i]) {
            max = ret;
        }
        else {
            max = arr[i];
        }
    }
    printf("%d", max);

    return 0;
}