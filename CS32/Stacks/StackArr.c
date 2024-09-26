#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 101

typedef int StackElemType;

typedef struct stack
{
    int top;
    StackElemType Stack[n];
} Stack;

void InitStack(Stack *S)
{
    S->top = -1;
}

int IsEmptyStack(Stack *S)
{
    return (S->top == 0);
}

void StackOverflow()
{
    printf("Stack overflow detected.\n");
    exit(1);
}

void StackUnderflow()
{
    printf("Stack underflow detected.\n");
    exit(1);
}

void Push(Stack *S, StackElemType x)
{
    if (S->top == n)
    {
        StackOverflow();
    }
    else
    {
        ++S->top;
        S->Stack[S->top] = x;  
    }
}

void Pop(Stack *S, StackElemType *x)
{
    if (S->top == 0)
    {
        StackUnderflow();
    }
    else
    {
        --S->top;
        *x = S->Stack[S->top];  
    }
}

void BuildStack(Stack *S)
{
    char *arr = "hello world";
    int len = strlen(arr);
    for (int i = 0; i < len; i++) Push(S, arr[i]);
}

void DisplayStack(Stack *S)
{
    int len = S->top;
    for (int i = 0; i <= len; i++)
    {
        printf("%c", S->Stack[i]);
    }
    printf("\n");
}

void ReverseStack(Stack *S, Stack *T, int tite)
{
    int len = S->top;
    for (int i = 0; i < len; i++)
    {
        Pop(S, &tite);
        Push(T, tite);
    }
}

void RemoveCharacter(Stack *S, Stack *T, int tite)
{
    int len = S->top;
    for (int i = 0; i < len; i++)
    {
       if (S->Stack[i] != 'o')
       {
         Push(T, S->Stack[i]);
       }
    }
}

int main()
{
    Stack S, T; StackElemType x; int tite;
    InitStack(&S);
    InitStack(&T);
    BuildStack(&S);
    DisplayStack(&S);
    // DisplayStack(&S);
    // ReverseStack(&S, &T, tite);
    // DisplayStack(&T);

    return 0;
}
