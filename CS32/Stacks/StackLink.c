#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int StackElemType;
typedef struct stacknode StackNode;
struct stacknode
{
    StackElemType val;
    StackNode *next;
};

struct stack
{
    StackNode *top;
};
typedef struct stack Stack;

void InitStack(Stack *S)
{
    S->top = NULL;
}

int IsEmptyStack(Stack *S)
{
    return (S->top == NULL);
}

void StackOverflow()
{
    printf("Stackoverflow");
    exit(1);
}

void StackUnderflow()
{
    printf("Stackunderflow");
    exit(1);
}

void Push(Stack *S, StackElemType x)
{
    StackNode *head = (StackNode*)malloc(sizeof(StackNode));
    if (head == NULL)
    {
        StackOverflow();
    }
    else
    {
        head->val = x;
        head->next = S->top;
        S->top = head;
    }
}

void Pop(Stack *S, StackElemType *x)
{
    StackNode *head = (StackNode*)malloc(sizeof(StackNode));
    if (S->top == NULL)
    {
        StackUnderflow();
    }
    else
    {
        head = S->top;
        *x = S->top->val;
        S->top = S->top->next;
        free(head);
    }
}

void BuildStack(Stack *S)
{
    Push(S, 1);
    Push(S, 2);
}

void Display(Stack *S, StackNode *Head)
{
    while (Head)
    {
        printf("%d -> ", Head->val);
        Head = Head->next;
    }
    printf("NULL");
}


int main()
{
    Stack S;
    InitStack(&S);
    BuildStack(&S);
    Display(&S, S.top);
}