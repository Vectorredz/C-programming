#include <stdio.h>
#include <stdlib.h>

#define n 12

typedef int QueueElemType;

typedef struct queue {
    int front; 
    int rear; 
    QueueElemType *Queues;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = -1; 
    Q->rear = -1; 
    Q->Queues = (QueueElemType*)malloc(n * sizeof(QueueElemType));
}

void ENQUEUE(Queue *Q, QueueElemType x) {
    if (Q->rear == n - 1) return; 
    if (Q->front == -1) Q->front++; 
    Q->rear++;
    Q->Queues[Q->rear] = x;
}

void DEQUEUE(Queue *Q, QueueElemType *x) {
    if (Q->front == -1 || Q->front > Q->rear) { 
        return;
    }
    *x = Q->Queues[Q->front];
    Q->front++;
    if (Q->front > Q->rear) { 
        Q->front = -1;
        Q->rear = -1;
    }
}

void Display(Queue *Q) {
    for (int i = Q->front; i <= Q->rear; i++) {
        printf("%d ", Q->Queues[i]);
    }
    printf("\n");
}

int peek(Queue *Q){
    return Q->Queues[Q->front];
}
void REVERSE(Queue *Q, int k);

void reverseFirstK(Queue *Q, int k){
    int len = Q->rear +1 ;
    int temp;
    REVERSE(Q, k);
    int s = len - k;
    while (s-- > 0){
        int x = peek(Q);
        DEQUEUE(Q, &temp);
        ENQUEUE(Q, x);
    }
}

// using two queues
void REVERSE(Queue *Q, int k){
    int temp;
    if (k == 0) return;
    int x = peek(Q);
    DEQUEUE(Q, &temp);
    REVERSE(Q, k-1);
    ENQUEUE(Q, x);
}

// void REVERSE(Queue *Q) {
//     QueueElemType x;
//     if (Q->front == -1) {
//         return;
//     }
//     DEQUEUE(Q, &x); 
//     REVERSE(Q); 
//     ENQUEUE(Q, x); 
// }

int main() {
    Queue Q; 
    Queue R;
    InitQueue(&Q);
    InitQueue(&R);
    int list[] = {1, 2, 3, 4, 5};
    int len = sizeof(list) / sizeof(list[0]);
    
    for (int i = 0; i < len; i++) {
        ENQUEUE(&Q, list[i]);
    }
    Display(&Q);
    reverseFirstK(&Q, 3);
    Display(&Q);
    return 0;
}
