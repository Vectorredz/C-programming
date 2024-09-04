#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char s[]) {
    int len = strlen(s);
    bool ret = true;

    if (len == 0) {
        return ret;
    }
    else {
        char sub[len - 1];
        strncpy(sub, &s[1], len - 2);
        sub[len - 2] = '\0';
        return palindrome(sub);
    }
}

int main() {
    char s[] = "BANANA";
    bool cost = palindrome(s);

    printf("%d\n", cost);

    return 0;
}
