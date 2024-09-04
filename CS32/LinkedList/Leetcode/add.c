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
    head->val = 2;
    head->next = second;

    second->val = 4;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 3;
    fifth->next = NULL;

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
    head->val = 9;
    head->next = second;

    second->val = 9;
    second->next = third;

    third->val =9;
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

Node *addTwoNumbers(Node *l1, Node *l2){
    Node dummy;
    Node *curr = &dummy;
    dummy.next = NULL;
    int carry = 0;
    while (l1 || l2 || carry){
        Node *sum = (Node*)malloc(sizeof(Node));
        sum->val = (l1 ? l1->val : 0)+ (l2 ? l2->val : 0) + carry;
        sum->next = NULL;
        carry = sum->val / 10;
        sum->val = sum->val % 10;
        // if (sum->val > 9){
        //     sum->val = abs(10 - sum->val);
        //     carry = 1;
        // }
        curr->next = sum;
        curr = sum;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    // if (l1){
    //     l1->val = l1->val + carry;
    //     curr->next = l1;
    // }
    // if (l2){
    //     curr->next = l2;
    // }
    return dummy.next;





    // while (head1 != NULL && head2 != NULL){
    //     Node *curr = (Node*)malloc(sizeof(Node));
    //     curr->val = head1->val + head2->val;
    //     if (curr->val > 9){
    //         curr->val = 0;
    //         curr->next = res;
    //         nextNode->val = nextNode->val + 1;
    //     }
    //     curr->next = res;
    //     res = curr;
    //     nextNode = curr;
    //     head1 = head1->next; // store the next nodes;
    //     head2 = head2->next;
    // // }

    // return res;
}


int main(){
    Node *l1 = Build1();
    Node *l2 = Build2();
    Node *ret = NULL;
    display(l1);
    display(l2);

    ret = addTwoNumbers(l1, l2);
    display(ret);

}