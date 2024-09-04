#include <stdio.h>

int range(int x, int y, int z){
    if (20 <= x && x <= 50 || 20 <= y && y <= 50 || 20 <= z && z <= 50 ){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int x, y, z;
    printf("Enter a value for x: ");
    scanf("%d", &x);
    printf("Enter a value for y: ");
    scanf("%d", &y);
    printf("Enter a value for z: ");
    scanf("%d", &z);
    int ret = range(x, y, z);
    printf("%d", ret);
}