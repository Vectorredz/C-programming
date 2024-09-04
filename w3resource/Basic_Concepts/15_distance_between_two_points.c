#include <stdio.h>
#include <math.h>

double *distance_solver(int x1, int y1, int x2, int y2, double *ret){
    *ret  = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));


}

int main(){
    int x1, y1, x2, y2;
    double *ret;
    printf("Input x1: ");
    scanf("%d", &x1);
    printf("Input y1: ");
    scanf("%d", &y1);
    printf("Input x2: ");
    scanf("%d", &x2);
    printf("Input y2: ");
    scanf("%d", &y2);
    
    distance_solver(x1, y1, x2, y2, &ret);
    printf("%f", *ret);
} 