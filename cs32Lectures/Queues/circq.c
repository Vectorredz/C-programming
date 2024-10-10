#include <stdio.h>
#include <stdlib.h>

#define n 12  

typedef int QueueElemType;
typedef struct queue {
    int front;
    int rear;
    QueueElemType *Queue;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->Queue = (QueueElemType*)malloc(n * sizeof(QueueElemType));
}

int IsEmptyQueue(Queue *Q) {
    return (Q->front == Q->rear); 
}

int IsFullQueue(Queue *Q) {
    return ((Q->rear + 1) % n == Q->front);
}

void QueueOverflow() {
    printf("Queue overflow detected.\n");
    exit(1);
}

void QueueUnderflow() {
    printf("Queue underflow detected.\n");
    exit(1);
}

void ENQUEUE(Queue *Q, QueueElemType x) {
    if (IsFullQueue(Q)) {
        QueueOverflow();  
    } else {
        Q->Queue[Q->rear] = x;              
        Q->rear = (Q->rear + 1) % n;        
    }
}

void DEQUEUE(Queue *Q, QueueElemType *x) {
    if (IsEmptyQueue(Q)) {
        QueueUnderflow(); 
    } else {
        *x = Q->Queue[Q->front];            
        Q->front = (Q->front + 1) % n;     
    }
}

void Display(Queue *Q) {
    if (IsEmptyQueue(Q)) {
        printf("Queue is empty.\n");
    } else {
        int i = Q->front;
        while (i != Q->rear) {
            printf("%d ", Q->Queue[i]);
            i = (i + 1) % n;               
        }
        printf("\n");
    }
}

void Build(Queue *Q) {
    for (int i = 1; i <= 5; i++) {
        ENQUEUE(Q, i);                      
    }
}

int main() {
    Queue Q;
    QueueElemType x;

    InitQueue(&Q);
    Build(&Q);
    Display(&Q); 
    DEQUEUE(&Q, &x);
    Display(&Q);  

    return 0;
}
