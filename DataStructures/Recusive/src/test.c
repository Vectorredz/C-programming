#include <stdio.h>
#include <string.h>

int symmetry_cost(char s[]) {
    int len = strlen(s);

    if (len == 0) {
        return 0;
    }

    if (s[0] != s[len - 1]) {
        // Create a new substring excluding the first and last characters
        char sub[len - 1];
        strncpy(sub, &s[1], len - 2);
        sub[len - 2] = '\0';

        // Return 1 + the symmetry cost of the substring
        return 1 + symmetry_cost(sub);
    } else {
        // Create a new substring excluding the first and last characters
        char sub[len - 1];
        strncpy(sub, &s[1], len - 2);
        sub[len - 2] = '\0';

        // Return the symmetry cost of the substring
        return symmetry_cost(sub);
    }
}

int main() {
    char s[] = "BANANA";
    int cost = symmetry_cost(s);

    printf("Symmetry cost: %d\n", cost);

    return 0;
}
