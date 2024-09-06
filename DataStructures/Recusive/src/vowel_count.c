#include <stdio.h>
#include <string.h>

int vowel_count(char s[]){
    int len = strlen(s);

    if (len == 0){
        return 0;
    }
    else if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
        char sub[len - 1];
        strncpy(sub, &s[1], len);
        sub[len - 1] = '\0';
        return 1 + vowel_count(sub);
    }
    else {
        char sub[len - 1];
        strncpy(sub, &s[1], len);
        sub[len - 1] = '\0';
        return vowel_count(sub);
    }

}

int main(){
    char s[] = "anana";
    int cost = vowel_count(s);

    printf("Symmetry cost: %d\n", cost);

}


