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
    Q->front = -1;  
    Q->rear = -1;  
    Q->Queue = (QueueElemType*)malloc(n * sizeof(QueueElemType));
}

int IsEmptyQueue(Queue *Q) {
    return (Q->front == Q->rear); 
}

int IsFullQueue(Queue *Q) {
    return (Q->rear == n - 1);  
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
        Q->rear = Q->rear + 1;  
        Q->Queue[Q->rear] = x;  
    }
}

void DEQUEUE(Queue *Q, QueueElemType *x) {
    if (IsEmptyQueue(Q)) {
        QueueUnderflow(); 
    } else {
        Q->front = Q->front + 1;  
        *x = Q->Queue[Q->front];  
    }
}

void Display(Queue *Q) {
    if (IsEmptyQueue(Q)) {
        printf("Queue is empty.\n");
    } else {
        for (int i = Q->front + 1; i <= Q->rear; i++) {
            printf("%d ", Q->Queue[i]);
        }
        printf("\n");
    }
}

void Build(Queue *Q) {
    int *x;
    for (int i = 1; i <= 12; i++) {
        ENQUEUE(Q, i); 
    }
}

int main() {
    Queue Q;
    QueueElemType x;

    InitQueue(&Q);
    Build(&Q);
    // Build(&Q);
    Display(&Q); 
    // Display(&Q);  

    return 0;
}
