// max(x, y) -> div_5(x,y) -> return 

#include <stdio.h>


int test(int x, int y);

int main(){
    printf("%d",test(11, 21));
    printf("\n%d",test(11, 20));
    printf("\n%d",test(10, 10));
}

int max(int x, int y){
    if (x > y){
        return x;
    }
    else if (y > x) {
        return y;
    } 
    else {
        return 0;
    }
}

int min(int x, int y){
    if (x > y){
        return y;
    }
    else if (y > x) {
        return x;
    } 
    else {
        return 0;
    }
}

int test(int x, int y){

    int maxed = max(x, y);
    int mined = min(x, y);
    if ((x % 5 == y % 5)){
        return mined;
    }
    else if ((x % 5 != y % 5)){
        return maxed;
    }
    else {
        return 0;
    }
}