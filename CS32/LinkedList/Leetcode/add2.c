#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node Node;
struct node{
    int val;
    Node *next;
};

// build 1 -> 2 -> 3 -> null list;

Node *Build1(){
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
    head->val = 7;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 4;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = NULL;

    return head;
}

Node *Build2(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    //allocate memory

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    //define val; next;
    head->val = 5;
    head->next = second;

    second->val = 6;
    second->next = third;

    third->val =4;
    third->next = NULL;

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

Node *popTail(Node **head){
    Node *curr = *head;
    Node *prev = NULL;
    if (*head == NULL){
        return NULL;
    }
    while (curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL){
        *head = NULL;
    }
    else{
        prev->next = NULL;

    }
    return curr;
}

Node *reverse(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *store = NULL;
    while (curr != NULL){
        store = curr->next;
        curr->next = prev;
        prev = curr;
        curr = store;
    }
    return prev;
}

Node *addTwoNumbers(Node *l1, Node *l2){
    Node dummy;
    Node *curr = &dummy;
    dummy.next = NULL;
    int carry = 0;
    while (l1 || l2 || carry){
        Node *n1 = popTail(&l1); 
        Node *n2 = popTail(&l2);
        Node *sum = (Node*)malloc(sizeof(Node));
        sum->val = (n1 ? n1->val : 0)+ (n2 ? n2->val : 0) + carry;
        sum->next = NULL;
        carry = sum->val / 10;
        sum->val = sum->val % 10;
        
        curr->next = sum;
        curr = sum;
    }
    return reverse(dummy.next);
}





int main(){
    Node *l1 = Build1();
    Node *l2 = Build2();
    Node *ret = NULL;
    display(l1);
    ret = reverse(l1);
    display(ret);
    // display(l2);
    // ret = addTwoNumbers(l1, l2);
    // display(l1);
    // ret = popTail(&l1);
    // display(l1);
    // display(ret);
}