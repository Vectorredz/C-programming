#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node Node;
struct node{
    int data;
    Node *next;
};

Node *testNodes(){
    Node *head = NULL; Node *second = NULL; Node *third = NULL; 
    Node *fourth = NULL; Node *fifth = NULL; Node *sixth = NULL;
    head = (Node*)malloc(sizeof(Node)); second = (Node*)malloc(sizeof(Node)); third = (Node*)malloc(sizeof(Node)); fourth = (Node*)malloc(sizeof(Node)); fifth = (Node*)malloc(sizeof(Node)); sixth = (Node*)malloc(sizeof(Node));
    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = NULL;
    fifth->data = 5; fifth->next = NULL;
    // sixth->data = 6; sixth->next = NULL;

    return head;
}

int length(Node *head){
    Node *list = head;
    int count = 0;

    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}


void display(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("\t%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

void FrontBackSplit(Node *test, Node **frontRef, Node **backRef){
    Node *slow = test;
    Node *fast = test;
    Node *prev = NULL;
    if ((slow->next == NULL) || (slow == NULL)){
        assert(0);
    }
    while (fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (length(test) % 2==0){
        *frontRef = test;
        *backRef = slow;
        prev->next = NULL;
    }
    else {
        *frontRef = test;
        *backRef = slow->next;
        slow->next = NULL;
    }

}
int main(){
    Node *test = testNodes();
    Node *frontRef = NULL;
    Node *backRef = NULL;
    display(test);
    FrontBackSplit(test, &frontRef, &backRef);
    display(frontRef);
    display(backRef);

}