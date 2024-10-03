#include <stdio.h>
#include <stdlib.h>

typedef int DequeElemtype;

// create node

typedef struct dequeNode
{
    DequeElemtype data;
    struct dequeNode *next;
    struct dequeNode *prev;

} DequeNode;

typedef struct deque
{
    DequeNode * front;
    DequeNode  * rear;
} Deque;

void InitDeque(Deque *D)
{
    D->front = NULL;
    D->rear = NULL;
}

int isEmpty(Deque *D)
{
    return (D->front == NULL);
}

void ENQUEUE_FRONT(Deque *D, DequeElemtype x)
{
    DequeNode *newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if (newNode == NULL)
    {
        exit(1);
    }
    
    newNode->data = x;
    newNode->next = D->front;
    newNode->prev = NULL;
    if (isEmpty(D)){
        D->rear = newNode;
    }
    else {
        D->front->prev = newNode;
    }
    D->front = newNode;
}

void ENQUEUE_REAR(Deque *D, DequeElemtype x)
{
    DequeNode *newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if (newNode == NULL)
    {
        exit(1);
    }
    
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = D->rear;

    if (isEmpty(D))
    {
        D->front = newNode;
    } else {
        D->rear->next = newNode;
    }
    D->rear = newNode;
}

void DEQUEUE_FRONT(Deque *D, DequeElemtype *x)
{

    if (D->front == D->rear){
        D->front = D->rear = NULL;
    } else {
        *x = D->front->data;
        D->front = D->front->next;
        D->front->prev = NULL;
    }
}

void DEQUEUE_REAR(Deque *D, DequeElemtype *x)
{
    if (D->rear == D->front){
       D->front = D->rear = NULL; 
    }
    else
    {
        *x = D->rear->data;
        D->rear = D->rear->prev;
        D->rear->next = NULL;
    }
}

void REVERSE(Deque *D)
{
    DequeNode *current = D->front;
    DequeNode *temp = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = D->front;
    D->front = D->rear;
    D->rear = temp;
}


void Display(Deque *D)
{
    DequeNode *current = D->front;
    while(current)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    

}

int main()
{
    Deque Q;
    DequeElemtype x;
    InitDeque(&Q);
    Display(&Q);
    ENQUEUE_REAR(&Q, 1);
    ENQUEUE_REAR(&Q, 2);
    ENQUEUE_FRONT(&Q, 1);
    REVERSE(&Q);
    Display(&Q);
    printf("\n%d", x);

}