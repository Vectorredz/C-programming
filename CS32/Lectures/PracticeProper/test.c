#include <stdio.h>
#include <string.h>
#include <math.h>

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

int main() {
    char val[] = "0xacd777";
    int len = strlen(val);
    strrev(val)[len-2] = '\0'; 
    strrev(val);
    printf("%d", hex_converter(val, strlen(val)));
}

    
