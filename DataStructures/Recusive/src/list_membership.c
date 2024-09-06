#include <stdio.h>
#include <string.h>

int is_member(int elem, char *elems){
    if (*elems == '\0') {
        return 0;
    }
    else if (*elems == elem){
        return 1;
    }
    else {
        return is_member(elem, elems + 1);
    }
}

int main(){
    int x = 5;
    char y[] = {1,2,3,4, '\0'};
    int ret = is_member(x, y);
    if (ret == 1){
        printf("True");
    }
    else {
        printf("False");
    }
    return 0;
}