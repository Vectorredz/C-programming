// 141. Linked List Cycle

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

    //allocate memory

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    fifth = (Node*)malloc(sizeof(Node));

    //define val; next;
    head->val = 0;
    head->next = second;

    second->val = 1;
    second->next = third;

    third->val = 2;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 4;
    fifth->next = third;

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

bool hasCycle(Node *head){
    Node *slow = NULL;
    Node *fast = NULL;
    Node *curr = head;

    while (fast != NULL && fast->next != NULL && slow != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    Node *head = Build();
    int ret = hasCycle(head);
    printf("%d ", ret);
}