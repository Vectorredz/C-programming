// 83. Remove Duplicates from Sorted List

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int val;
    Node *next;
};

// build 1 -> 2 -> 3 -> null list;

Node *BuildOneTwoThree(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *f = NULL;
    Node *g = NULL;

    //allocate memory

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    f = (Node*)malloc(sizeof(Node));
    g = (Node*)malloc(sizeof(Node));

    //define val; next;
    head->val = 0;
    head->next = second;

    second->val = 0;
    second->next = third;

    third->val = 0;
    third->next = f;

    f->val = 0;
    f->next = g;

    g->val = 0;
    g->next = NULL;

    return head;
}

void display(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("\t%d-> ", current->val);
        current = current->next;
    }
    printf("\n");
}

Node *deleteDuplicates(Node *head){
    Node dummy;
    dummy.next = head;
    Node *current = head;
    Node *nextNode = NULL;


    if (head == NULL){
        return NULL;
    }
    while (current != NULL && current->next != NULL){
        if (current->val == current->next->val){
            nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        }
        else {
            current = current->next;

        }
    }
    return dummy.next;
}

int main(){
    Node *head = BuildOneTwoThree();
    display(head);
    head = deleteDuplicates(head);
    display(head);


}
