#include <stdio.h>

void reverse(char *Characters, int *len){
    for (int i = *len-1; i >= 0; i--){
        printf("%c", Characters[i]);
    }
}


int main(){
    char Characters[3] = {'X', 'M', 'L'};
    int len = sizeof(Characters) / sizeof(Characters[0]);
    reverse(Characters, &len);
    


}