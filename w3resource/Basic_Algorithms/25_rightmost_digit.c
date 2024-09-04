#include <stdio.h>

int test(int x, int y, int z)
{
    // Check if the last digit of 'x' is equal to the last digit of 'y' or 'z'
    // or if the last digit of 'y' is equal to the last digit of 'z'
    if (x % 10 == y % 10 || x % 10 == z % 10 || y % 10 == z % 10) {
        return 1; // If any of these conditions is true, return 1
    } else {
        return 0; // If none of the conditions is true, return 0
    }
}

int main(){
    // Print the result of calling 'test' with different integer values and format the output
    printf("%d",test(11, 21, 31));
    printf("\n%d",test(11, 22, 31));
    printf("\n%d",test(11, 22, 33));
}

// Function definition for 'test'
