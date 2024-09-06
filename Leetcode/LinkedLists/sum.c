// 1945. Sum of Digits of String After Convert
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}Node;

//build nodes

Node *List1(){
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;

    head = (Node*)malloc(sizeof(Node));
    first = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));

    head->val = 1;
    head->next = first;

    first->val = 2;
    first->next = second;

    second->val = 4;
    second->next = NULL;

    return head;
}
Node *List2(){
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;

    head = (Node*)malloc(sizeof(Node));
    first = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));

    head->val = 1;
    head->next = first;

    first->val = 3;
    first->next = second;

    second->val = 4;
    second->next = NULL;

    return head;
}
//display

Node *Display(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("\n");
}

// 1. Merge 

// void *sortedInsert(Node **head, Node *newNode);

// Node *mergeTwoLists(Node *list1, Node *list2){
//     Node *merge = (Node*)malloc(sizeof(Node));
//     Node *current = list2;
//     Node *nextNode = NULL;
//     while (current != NULL){
//         nextNode = current->next;
//         sortedInsert(&list1, current);
//         current = nextNode;
//     }
//     merge = list1;
//     return merge;
// }

// void *sortedInsert(Node **head, Node *newNode){
//     Node *current = *head;
//     Node *previous = NULL;
//     if (*head == NULL){
//         *head = newNode;
//     }
//     else if (newNode->val < current->val){
//         newNode->next = current;
//         *head = newNode;
//     }
//     else {
//         while (current->next != NULL){
//             previous = current;
//             current = current->next;
//             if (newNode->val < current->val){
//                 previous->next = newNode;
//                 newNode->next = current;
//                 break;
//                 }
//         }
//         if (current->val <= newNode->val){
//             current->next = newNode;
//             newNode->next = NULL;
//         }
//     }
// }
// //

Node *mergeTwoLists(Node *list1, Node *list2){
    Node dummy;
    Node *current = &dummy;

    dummy.next = list1;

    if (list1 == NULL && list2 == NULL){
        return NULL;
    }

    while (list1 && list2){
        if (list1->val < list2->val){
            current->next = list1;
            list1 = list1->next;
            current = current->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
            current = current->next;
        }
    }
    if (list1) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }
    return dummy.next;
}
int main(){
    Node *head1 = List1();
    Node *head2 = List2();
    Display(head1);

    Node *ret = merge(head1, head2);

    // Node *ret = mergeTwoLists(head1, head2);

    Display(ret);
    // Display(head2);

    // Node* newHead = mergeTwoLists(head1, head2);

    // Display(newHead);


    return 0;
}