#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int val;
    Node* next;
};

void freeLL(Node *head){ // {1,2,3}
    Node *nextNode;
    while (head != NULL){
        nextNode = head->next;  // 2 3 
        free(head); // 1
        head = nextNode; // 2 3 
    }
}

void displayLL(Node *head){
    while (head != NULL){
        printf(" %d-> ", head->val);
        head = head->next;
    }
}

int main(){
    int LL[] = {1,2,3,4,5};
    int len = sizeof(LL) / sizeof(LL[0]);
    Node *list = (Node*)malloc(sizeof(Node));
    Node *curr;
    curr->next = NULL;
    list->next = NULL;
    for (int i = 0; i < len; i++){
        if (i==0){ // create head of list
            list->val = LL[i];
            curr = list; // current node (head)
        }
        else {
            // create every single node to link to list;
            Node *node = (Node*)malloc(sizeof(Node));
            node->val = LL[i];
            curr->next = node; // link the node to the current head
            curr = node; // will become the new head
        }
    }
    curr->next = NULL; // curr will link to null; hence it will become the tail

    displayLL(list);
    freeLL(list);

}