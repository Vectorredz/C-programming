#include <stdio.h>
#include <stdlib.h>

typedef int DequeElemtype;

// Node structure for the deque
typedef struct dequeNode {
    DequeElemtype data;
    struct dequeNode* next;
    struct dequeNode* prev;
} DequeNode;

// Deque structure with front and rear pointers
typedef struct deque {
    DequeNode* front;
    DequeNode* rear;
} Deque;

// Initialize the deque
void InitDeque(Deque* D) {
    D->front = NULL;
    D->rear = NULL;
}

// Check if deque is empty
int isEmpty(Deque* D) {
    return (D->front == NULL);
}

// Enqueue at the front
void ENQUEUE_FRONT(Deque* D, DequeElemtype x) {
    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = x;
    newNode->next = D->front;
    newNode->prev = NULL;
    if (isEmpty(D)) {
        D->rear = newNode;
    } else {
        D->front->prev = newNode;
    }
    D->front = newNode;
}

// Enqueue at the rear
void ENQUEUE_REAR(Deque* D, DequeElemtype x) {
    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = D->rear;
    if (isEmpty(D)) {
        D->front = newNode;
    } else {
        D->rear->next = newNode;
    }
    D->rear = newNode;
}

// Dequeue from the front
void DEQUEUE_FRONT(Deque* D, DequeElemtype* x) {
    if (isEmpty(D)) {
        printf("Deque Underflow\n");
        return;
    }
    DequeNode* temp = D->front;
    *x = temp->data;
    if (D->front == D->rear) {  // Only one element
        D->front = D->rear = NULL;
    } else {
        D->front = D->front->next;
        D->front->prev = NULL;
    }
    free(temp);
}

// Dequeue from the rear
void DEQUEUE_REAR(Deque* D, DequeElemtype* x) {
    if (isEmpty(D)) {
        printf("Deque Underflow\n");
        return;
    }
    DequeNode* temp = D->rear;
    *x = temp->data;
    if (D->front == D->rear) {  // Only one element
        D->front = D->rear = NULL;
    } else {
        D->rear = D->rear->prev;
        D->rear->next = NULL;
    }
    free(temp);
}

// Reverse the deque
void REVERSE(Deque* D) {
    DequeNode* current = D->front;
    DequeNode* temp = NULL;
    
    // Traverse the deque and swap prev and next pointers
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Swap the front and rear pointers
    temp = D->front;
    D->front = D->rear;
    D->rear = temp;
}

// Display the deque from front to rear
void Display(Deque* D) {
    DequeNode* current = D->front;
    if (isEmpty(D)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Deque Q;
    DequeElemtype x;

    // Initialize deque
    InitDeque(&Q);

    // Enqueue some elements
    ENQUEUE_REAR(&Q, 1);
    ENQUEUE_REAR(&Q, 2);
    ENQUEUE_FRONT(&Q, 0);

    // Display the deque
    printf("Deque before reversing:\n");
    Display(&Q);

    // Reverse the deque
    REVERSE(&Q);
    
    // Display after reversing
    printf("Deque after reversing:\n");
    Display(&Q);

    // Dequeue from front
    DEQUEUE_FRONT(&Q, &x);
    printf("Dequeued from front: %d\n", x);

    // Dequeue from rear
    DEQUEUE_REAR(&Q, &x);
    printf("Dequeued from rear: %d\n", x);

    // Final display of the deque
    printf("Final Deque:\n");
    Display(&Q);

    return 0;
}
