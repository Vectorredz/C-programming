#include <stdio.h>

typedef struct node{
    int data;
    Node *next;
} Node;

Node *buildOneTwoThree(){
    Node *head = NULL;

    // allocate memory; add nodes in heap
    Node *head = (Node*)malloc(sizeof(Node));
    Node *two = (Node*)malloc(sizeof(Node));
    Node *three = (Node*)malloc(sizeof(Node));

    //initialize data; next
    head->data = 1;
    head->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    

}
// int main(){

// }