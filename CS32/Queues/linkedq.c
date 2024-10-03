#include <stdio.h>
#include <stdlib.h>

typedef int QueueElemType;
typedef struct queuenode QueueNode;
struct queuenode{
    QueueElemType data;
    QueueNode *next;
};

typedef struct queue{
    QueueNode *front;
    QueueNode *rear;
}Queue;

void InitQueue(Queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty(Queue *Q){
    return (Q->front == NULL);
}

void QueueOverflow(){
    exit(1);
}

void QueueUnderflow(){
    exit(1);
}

void ENQUEUE(Queue *Q, QueueElemType x){
    QueueNode *head;
    head = (QueueNode*)malloc(sizeof(QueueNode));
    if (head == NULL) QueueOverflow();
    else {
        head->data = x;
        head->next = NULL;
        // initialize the front and rear of Q
        if (Q->rear == NULL){
            // init to head
            Q->front = head;
            Q->rear = head;
        }
        // point rear of the queue to the node head
        // rear queue value = head->val 
        else{
            Q->rear->next = head;
            Q->rear = head;
        }
    }
}

void DEQUEUE(Queue *Q, QueueElemType *x){
    QueueNode *head;
    if (Q->front == NULL) QueueUnderflow();
    else {
        QueueNode *temp = Q->front;
        *x = temp->data;
        Q->front = Q->front->next;
    }
}

void Display(QueueNode *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
}

int main(){
    Queue Q;
    QueueElemType x;
    InitQueue(&Q);
    ENQUEUE(&Q, 1);
    ENQUEUE(&Q, 1);
    ENQUEUE(&Q, 1);
    Display(Q.front);


}