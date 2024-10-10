#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

void displayList(Node *head);

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

Node *removeList(Node *head){
    Node *current = head;
    Node *previous = NULL;
    while (current->next != NULL) {
        if (current->data == 2){
            if (previous == NULL){
                head = head->next;
            }
            else {
                previous = current->next;
            }
            return head;
        }
        previous = current;
        current = current->next;
    } 

    return head;
}

int length(Node *head){
    Node *list = head;
    int count = 0;

    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

int main() {
    Node *head = singleLinkedList();
    // displayList(head);
    addList(head);
    int ret = countList(head);
    printf("%d", ret);

    // Free allocated memory
    // Node *temp;
    // while (head != NULL) {
    //     temp = head;
    //     head = head->next;
    //     free(temp);
    // }

    return 0;
}
