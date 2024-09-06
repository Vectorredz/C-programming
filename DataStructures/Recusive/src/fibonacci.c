#include <stdio.h>

int ret(int s){
    if (s == 0){
        return 0;
    }
    else if (s==1 || s==2) {
        return 1;
    }
    else {
        return ret(s-1) + ret(s-2);
    }
}

int main(){
    int s = 10;
    int k = ret(s);

    printf("%d\n", k);

    return 0;  
}
