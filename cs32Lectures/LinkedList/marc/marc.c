#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
struct node{
    int data;
    NODE* next;
};

// helper function for printlist

void printList(NODE *head){
    NODE *current = head;
    while (current != NULL){
        printf("\t%d ->", current->data);
        current = current->next;
    }
    printf("\n");
}

// 1. NODE* createNode(int data);

NODE *createNode(int data){
    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->data = data;
    head->next = NULL;
}

// 2. int isEmpty(NODE *head);

int isEmpty(NODE *head){
    if (head == NULL){
        return 1; // is empty 
    }
    else {
        return 0;
    }
}

// 3. void insert(NODE **head);

void insert(NODE **head, int value){
    NODE *current = *head;
    // create newNode;
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode = createNode(value);

    current->next = newNode;
    newNode->next = NULL;
}

// 4. int delete(NODE **head);

int delete(NODE **head){
    *head = NULL;
}

int main(){
    int data; // initialize head
    data = 1;
    NODE *head = createNode(data);

    printList(head);

    data = 2;
    insert(&head, data);

    printList(head);

    delete(&head);

    printList(head);
    // int elems = isEmpty(head);
    // if (elems == 0){
    //     printf("is empty");
    // }
    // else {
    //     printf("non-empty");
    // }




}