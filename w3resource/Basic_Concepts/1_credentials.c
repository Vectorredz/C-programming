#include <stdio.h>

void ret(char *Name, char *Date, char * Mobile){
    printf("Name: %s \nDOB: %s \nMobile: %s", Name, Date, Mobile);
}

int main(){
    char Name[] = "Alexandra Abramove";
    char Date[] = "July 14, 1975";
    char Mobile[] = "99-9999999999";
    ret(Name, Date, Mobile);
}