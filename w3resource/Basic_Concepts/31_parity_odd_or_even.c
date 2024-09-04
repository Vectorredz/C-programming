#include <stdio.h>

int main() {
    int x; 
    printf("Test Data, input an integer: ");
    scanf("%d", &x);
    if (x % 2 != 0 && x > 0){
        printf("Expected Output: Positive Odd - %d", x);
    }
    else if (x % 2 != 0 && x < 0) {
        printf("Expected Output: Negative Odd - %d", x);
    }
    else if (x % 2 == 0 && x > 0) {
        printf("Expected Output: Positive Even - %d", x);
    }
    else if (x % 2 == 0 && x < 0) {
        printf("Expected Output: Negative Even - %d", x);
    }
    else {
        printf("Expected Output: Nonnegative - %d", x);
    }
}