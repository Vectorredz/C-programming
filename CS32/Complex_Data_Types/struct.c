#include <stdio.h>

struct fraction{
    int numerator;
    int denominator;
};

int main(){
    struct fraction numbers[10];
    int j = 0;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++){
    
        numbers[i].numerator = i;
        j = i;
        numbers[i].denominator = ++j;
        printf("%d %d\n", (struct fraction)numbers[i].numerator, (struct fraction)numbers[i].denominator);
    }
    


}