#include <stdio.h>

void reverse(char *strptr, char *rvptr){
    int i = 0;
    while (*strptr){
        *strptr++;
        i++;
    }

    while (i >= 0){
        *strptr--;
        *rvptr = *strptr;
        *rvptr++;
        --i;
    }


}

int main() {
    char str1[50] = "Sir Kevin Atienza";     
    char revstr[50];   
    char *stptr = str1;
    char *rvptr = revstr; // Pointer to the reversed string
    int i = -1; // Counter initialized with -1

    reverse(stptr, rvptr);

    printf("%s", rvptr);




    // while (*stptr) {
    //     stptr++; // Moving the pointer to the end of the string
    //     i++;     // Counting characters
    // }
    // while (i >= 0) {
    //     stptr--;             // Moving the pointer back to the last character of the original string
    //     *rvptr = *stptr;     // Assigning the character to the reversed string
    //     rvptr++;             // Moving the pointer to the next position in the reversed string
    //     --i;                 
    // }

    // *rvptr = '\0'; 


    // printf("%s\n\n", revstr);

    return 0;
}


