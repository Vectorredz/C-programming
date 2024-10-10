#include <stdio.h>
#include <math.h>

int is_prime(int n);

int primes(int a, int b){
    for (int i = a; i <= b; i++){
        if (is_prime(i) == 1){
            printf("%d ", i);
        }
    }
}

int is_prime(int n){
    if (n <= 1) return 0;
    if ((n % 2 == 0) || (n % 3 == 0)) return 0;
    if (n == 2 || n == 3) return 1;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    primes(a, b);
}