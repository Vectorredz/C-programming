// 83. Remove Duplicates from Sorted List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
struct node{
    int val;
    Node *next;
};


Node *BuildOneTwoThree(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *f = NULL;
    Node *g = NULL;


    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    f = (Node*)malloc(sizeof(Node));
    g = (Node*)malloc(sizeof(Node));

    head->val = 1;
    head->next = second;

    second->val = 1;
    second->next = third;

    third->val = 2;
    third->next = f;

    f->val = 1;
    f->next = NULL;



    return head;
}

Node *BuildO(){
    Node *head = NULL;
    Node *second = NULL;



    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));


    head->val = 0;
    head->next = second;

    second->val = 1;
    second->next = NULL;

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

// void push(Node **head, Node **insert);

Node *reverseList(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *store = NULL;
    while (curr){
        store = curr->next;
        curr->next = prev;
        prev = curr;
        curr = store;
    }
    return prev;
}

Node *copyListNode(Node *head){
    Node *curr = head;
    Node *copied = (Node*)malloc(sizeof(Node));
    copied = curr;
    return copied;

}

bool isPalindrome(Node *head) {
    Node *curr = head;
    Node *rev = reverseList(copyListNode(head));
    bool flag = false;
    while (curr->next != NULL && rev->next != NULL){
        if (curr->val != rev->val){
            flag = false;
            return flag;
        }
        curr = curr->next;
        rev = rev->next;
    }
    if (curr->val != rev->val){
        flag = false;
        return flag;
    }
    return flag;

    
}

// Node *reverseList(Node *head){
//     Node *newList = NULL;
//     // newList = (Node*)malloc(sizeof(Node));
//     Node dummy;
//     Node *current = head;
//     Node *store = NULL;
//     dummy.next = head;
//     while (current){
//         store = current->next;
//         push(&newList, &current);
//         current = store;
//     }
//     dummy.next = newList;
//     return dummy.next;
// }


// void push(Node **head, Node **insert){
//     Node *store = NULL;
//     Node *curr = *insert;
//     store = curr->next;
//     *insert = store; // isolate the curr;
//     curr->next = *head;
//     *head = curr;
// }



int main() {
    Node *head = BuildOneTwoThree();
    Node *new = BuildO();
    bool ret = isPalindrome(head);
    printf("%d", ret);
    // display(head);
    // head = reverseList(head);
    // display(head);
    return 0;
}

