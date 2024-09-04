#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b){
    unsigned int rem;
    while (b % a != 0){
        rem = b % a;
        b = a;
        a = rem;
    }
    return a;
}

int main(){
    unsigned int a, b;
    scanf("%u", &a);
    scanf("%u", &b);
    unsigned ret = gcd(a, b);

    if (ret != 0){
        printf("%u\n", a / ret);
        printf("%u", b / ret);
    }
    else {
        printf("Invalid; Zero Division Error");
    }
    // return 0;
}