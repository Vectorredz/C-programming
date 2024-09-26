#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 101

typedef int StackElemType;
typedef struct stack
{
    int top;
    StackElemType *x;
} stack;

void InitStack(stack *S)
{
    S->top = -1;
}
int IsFull(stack *S)
{
    return (S->top == n);
}



int main()
{

}