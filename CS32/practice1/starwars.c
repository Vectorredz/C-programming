#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strip(char *str, char *kstrip){
    int j = 0;
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            kstrip[j++] = str[i];
        }
    }
    kstrip[j] = '\0';
}

void lowercase(char *str, int len){
    for (int i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
}

int main() {
    char fname[100], mname[100], lname[100], home[100];
    char fstrip[100], mstrip[100], lstrip[100], hstrip[100];
    char genfirst[100], genlast[100];

    fgets(fname, 100, stdin);
    fgets(mname, 100, stdin);
    fgets(lname, 100, stdin);
    fgets(home, 100, stdin);

    strip(fname, fstrip);
    strip(lname, lstrip);
    strip(mname, mstrip);
    strip(home, hstrip);
    
    if (strlen(fstrip) < 3) {
        unsigned int len = strlen(fstrip);
        fstrip[len] = fstrip[len-1];
    }
    else{
        (fstrip[strlen(fstrip)] = '\0');
    }

    if (strlen(hstrip) < 3) {
        unsigned int len = strlen(hstrip);
        hstrip[len] = hstrip[len-1];
    }
    else{
        (hstrip[strlen(hstrip)] = '\0');
    }
    
    strrev(lstrip)[2] = '\0';
    hstrip[3] = '\0';
    lowercase(mstrip, strlen(mstrip));

    strcat(fstrip, strrev(lstrip));
    strcpy(genfirst, fstrip);
    strcat(hstrip, mstrip);
    strcpy(genlast, hstrip);

    printf("%s %s",genfirst, genlast);
    return 0;
}
