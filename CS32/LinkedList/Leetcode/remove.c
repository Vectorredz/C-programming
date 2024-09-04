// 203. Remove Linked List Elements

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node *next;
}Node;


Node *Build(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *sixth = NULL;
    Node *seventh = NULL;
    //allocate memory

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    fifth = (Node*)malloc(sizeof(Node));
    sixth = (Node*)malloc(sizeof(Node));
    seventh = (Node*)malloc(sizeof(Node));

    //define val; next;
    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 6;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 4;
    fifth->next = sixth;

    sixth->val = 5;
    sixth->next = seventh;

    seventh->val = 6;
    seventh->next = NULL;

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

Node *removeElements(Node *head, int val){
    Node dummy;
    Node *curr = &dummy;
    Node *nextNode = NULL;
    Node *store = NULL;
    dummy.next = head;
    if (head->val == val){
        head = curr->next;
    }
    while (curr->next != NULL && curr!= NULL){
        if (curr->next->val == val){
            nextNode = curr->next->next;
            free(curr->next);
            curr->next = nextNode;
        }
        else {
            curr = curr->next;
            nextNode = curr;
        }
    }
    return dummy.next;
}
int main(){
    Node *head = Build();
    display(head);
    head = removeElements(head, 1);
    display(head);
    
}