#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

void displayList(Node *head);

Node *buildList(){
    Node *head = NULL;
    Node *tail;

    return head;
}

Node *buildDummy(){
    Node dummy;
    Node *tail = &dummy;

    return tail;
}

Node *singleLinkedList() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // Allocate memory
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    // Give data and link nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

void displayList(Node *head) {
    Node *list = head;

    while (list != NULL) {
        printf("\t%d->", list->data);
        list = list->next;
    }
}

Node *insert_start(Node *head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 4;
    newNode->next = head;
    head = newNode;
    return head;
}


Node *push(Node **head, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    
}

Node *insert_end(Node *head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 4;
    newNode->next = NULL;
    Node *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *addList(Node *head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 4;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

int main() {
    // Node *head = buildList();
    Node *tail = buildDummy();
    Node node dummy;

    dummy->

    // push(&head, 1);
    // tail = head;

    // for (int i= 2; i<6; i++){
    //     push(&head, i);
    //     // push(&(tail->next), i);
    //     // tail = tail->next;
    // }
    // displayList(head);
}
