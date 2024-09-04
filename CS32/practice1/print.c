#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024
#define WIDTH 25

typedef struct ProcessInfo {
    int pid;
    char name[100];
    char stat[1];
    float cpu;
    char hexdump[100];
}Nigga;
unsigned int hex_converter(char *str, unsigned int len){
    unsigned int ret = 0;
    for (int i = 0; i < len; i++){
        switch (str[i]){
            case 'a':
                ret += 10 * pow(16, (len - 1 - i));
                break;
            case 'b':
                ret += 11 * pow(16, (len - 1 - i));
                break;
            case 'c':
                ret += 12 * pow(16, (len - 1 - i));
                break;
            case 'd':
                ret += 13 * pow(16, (len - 1 - i));
                break;
            case 'e':
                ret += 14 * pow(16, (len - 1 - i));
                break;
            case 'f':
                ret += 15 * pow(16, (len - 1 - i));
                break;
            default:
                int val = str[i] - '0';
                ret += (val * pow(16, (len - i - 1)));
                break;
        }
    }
    return ret;
}

int main(){
    Nigga input[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    int count = 0;
    int new_lines = 0;

    while (count < MAX_LINES){
        if (strcmp(buffer, "\n") == 0){
            new_lines += 1;
            if (new_lines == 2){
                break;
            }
        }
        fgets(buffer, MAX_LINE_LENGTH, stdin);
        if (sscanf(buffer, "%d %s %1s %f %s", &input[count].pid, input[count].name, input[count].stat, &input[count].cpu, input[count].hexdump) == 5) {
            count++;
        }
    }
    printf("|   pid|    cpu|stat|                     name| hexdump|\n");
    printf("+------+-------+----+-------------------------+--------+\n");
    for (int i = 0; i < count; i++){
        int len = strlen(input[i].hexdump);

        strrev(input[i].hexdump)[len-2] = '\0'; 
        strrev(input[i].hexdump);

        printf("|%*d|%*.5f|%*s|%*s|%*d| \n", 6, input[i].pid, 7, input[i].cpu, 4 , input[i].stat, WIDTH, input[i].name, 8, hex_converter(input[i].hexdump, strlen(input[i].hexdump)));
    }

}
