#include <stdio.h>

void ret_nums(int *elems, int len){
    if (len == 0){
        return;
    }
    else {
        elems[0] = elems[0] * elems[0];
        return ret_nums(elems + 1, len-1);
    }
}

int main(){
    int nums[] = {1,2,3};
    int len = sizeof(nums) / sizeof(nums[0]);
    ret_nums(nums, len);
    for (int i = 0; i < len; i++){
        printf("%d ", nums[i]);
    }
}