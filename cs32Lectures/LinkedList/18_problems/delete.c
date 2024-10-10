#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

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

Node *delete_start(Node *head){
    head = head->next;
    return head;
}

Node *delete_end(Node *head){
    Node *current = head;
    while (current->next->next != NULL){
        current = current->next;
    }
    current->next = NULL;

    return head;
}




void displayList(Node *head) {
    Node *list = head;

    while (list != NULL) {
        printf("\t%d->", list->data);
        list = list->next;
    }
}


int main(){
    Node *head = singleLinkedList();
    head = delete_end(head);
    displayList(head);

}