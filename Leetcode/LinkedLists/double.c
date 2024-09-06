#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int data;
    Node *next;
};

// build 1 -> 2 -> 3 -> null list;

Node *BuildOneTwoThree(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    //allocate memory

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    //define data; next;
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

void display(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("\t%d-> ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node *twice(Node *head){
    //dummy
    Node dummy;
    Node *current = &dummy;

    dummy.next = head;

    while (current != NULL){
        current->data *= 2;
        current = current->next;
    }
    return dummy.next;
}
int main(){
    Node *node = BuildOneTwoThree();
    display(node);
    twice(node);
    display(node);
}