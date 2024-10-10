#include <stdio.h>
#include <stdlib.h>

typedef int DequeElemType;

// doubly-linked list
struct DequeNode {
    DequeElemType data;
    struct DequeNode* next;
    struct DequeNode* prev;
};

struct Deque {
    struct DequeNode* front;
    struct DequeNode* rear;
};

void InitDeque(struct Deque* D) {
    D->front = NULL;
    D->rear = NULL;
}

int isEmpty(struct Deque* D) {
    return (D->front == NULL);
}

void ENQUEUE_REAR(struct Deque* D, DequeElemType x) {
    struct DequeNode* newNode = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    if (newNode == NULL) {
        printf("Memory overflow\n");
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

void Display(struct DequeNode* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void ReverseDeque(struct Deque* D) {
    if (isEmpty(D)) return;

    struct DequeNode* current = D->front;
    struct DequeNode* temp = NULL;

    // Traverse the list and swap next and prev pointers for each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to the next node (which is previous in original order)
    }

    // Swap the front and rear pointers of the deque
    temp = D->front;
    D->front = D->rear;
    D->rear = temp;
}

int main() {
    struct Deque D;
    InitDeque(&D);
    
    // Inserting elements
    ENQUEUE_REAR(&D, 10);
    ENQUEUE_REAR(&D, 20);
    ENQUEUE_REAR(&D, 30);
    ENQUEUE_REAR(&D, 40);

    // Display original deque
    printf("Original Deque: ");
    Display(D.front);

    // Reverse the deque
    ReverseDeque(&D);

    // Display reversed deque
    printf("Reversed Deque: ");
    Display(D.front);

    return 0;
}
