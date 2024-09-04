#include <stdio.h>

int divisiblity(int x){
    if (x % 7 == 0 && x % 3 == 0) {
        return 0;
    }
    else if (x % 7 == 0 || x % 3 == 0){
        return 1;
    }
    else {
        return 0;
    }

}

int main(){
    int x;
    printf("Enter value of x: ");
    scanf("%d", &x);
    int ret = divisiblity(x);
    printf("%d", ret);



}