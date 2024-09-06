#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *Build2(Node *intersect) {
    Node *head = NULL;
    Node *second = NULL;

    // Allocate memory
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));

    // Define val; next;
    head->val = 5;
    head->next = second;

    second->val = 6;
    second->next = intersect;  // Intersection starts here

    return head;
}

Node *Build1() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // Allocate memory
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    // Define val; next;
    head->val = 4;
    head->next = second;

    second->val = 1;
    second->next = third;

    // Create a common intersecting part
    third->val = 8;
    third->next = (Node*)malloc(sizeof(Node)); // Allocate memory for the next node
    third->next->val = 4;
    third->next->next = (Node*)malloc(sizeof(Node)); // Allocate memory for the next node
    third->next->next->val = 5;
    third->next->next->next = NULL;

    return head;
}

void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

Node *getIntersectionNode(Node *headA, Node *headB) {
    Node *a = headA;
    Node *b = headB;
    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;
}

int main() {
    Node *ListA = Build1();
    Node *ListB = Build2(ListA->next->next);  // Pass the intersection node

    display(ListA);
    display(ListB);

    Node *ret = getIntersectionNode(ListA, ListB);
    display(ret);

    return 0;
}
