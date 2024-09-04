#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node{
    int data;
    Node *next;
} Node;

Node *BuildOneTwoThree(){
    Node *head = NULL; Node *second = NULL; Node *third = NULL; 
    Node *fourth = NULL; Node *fifth = NULL; Node *sixth = NULL;
    head = (Node*)malloc(sizeof(Node)); second = (Node*)malloc(sizeof(Node)); third = (Node*)malloc(sizeof(Node)); fourth = (Node*)malloc(sizeof(Node)); fifth = (Node*)malloc(sizeof(Node)); sixth = (Node*)malloc(sizeof(Node));
    head->data = 1; 
    head->next = second;
    second->data = 2; 
    second->next = third;
    third->data = 3; 
    third->next = fourth;
    fourth->data = 4; 
    fourth->next = fifth;
    fifth->data = 5; 
    fifth->next = NULL;
    // fifth->data = ;
    // fifth->next = NULL;
    // sixth->data = 6;
    // sixth->next = NULL;

    return head;
}

Node *DeckA(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    

    return head;
}

Node *DeckB(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    fifth = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 6;
    third->next = NULL;

    return head;
}

void displayList(Node *head){
    Node *list = head;

    while (list != NULL) {
        printf("\t%d->", list->data);
        list = list->next;
    }
    printf("\n");
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

// 1 - Count() 
int Count(Node *head, int val){
    Node *current = head;
    int count = 0;
    while (current != NULL){
        if (current->data == val){
            count++;
        }
        current = current->next;
    }
    return count;
}

// 2 — GetNth()
int GetNth(Node **head, int index){
    Node *current = *head;
    int i = 0;
    while (current != NULL){
        if (i == index){
            return current->data;
        }
        i++;
        current = current->next;
    }
    assert(0);
    return 0;
}

// 3 — DeleteList()
void DeleteList(Node **head){
    Node *current = *head; // tail
    Node *nextNode = NULL;
    while (current->next != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

// 4 — Pop()
int Pop(Node **head){
    if (*head == NULL){
        assert(0);
    }
    int popped;
    Node *current = *head;
    *head = current->next;
    popped = current->data;
    free(current);
    return popped;
}

// 5 - InsertNth : inserts node to idx; val

int InsertNth(Node **head, int index, int val){
    int i = 0;
    Node *previous = NULL;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    Node *current = *head;
    if (index == 0){
        newNode->next = current;
        *head = newNode;
        return i;
    }
    while (current != NULL){
        if (i == index){
            previous->next = newNode;
            newNode->next = current;
            return i;
        }
        previous = current;
        current = current->next;
        i++;
    if ((current == NULL)){
        previous->next = newNode;
        newNode->next = current;
        current = NULL;
    }
}
}

void sorted_insert(Node **head, Node *newNode){
    Node *current = *head;
    Node *previous = NULL;
    if (current == NULL || newNode->data < current->data){
        newNode->next = current;
        *head = newNode;
        return;
    }
    while (current->next != NULL && current->data < newNode->data){
        previous = current;
        current = current->next;
    }
    if (newNode->data >= current->data){
        current->next = newNode;
        newNode->next = NULL;
        return;

    }
    previous->next = newNode;
    newNode->next = current;

}

void push(Node **head, Node *newNode){
    Node *current = *head;
    if (*head == NULL){
        *head = newNode;
        newNode->next = NULL;
    }
    else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
}

void insert_sort(Node **head){
    Node *sorted = NULL;
    Node *current = *head;
    Node *nextNode = NULL;
    while (current != NULL){
        nextNode = current->next;
        sorted_insert(&sorted, current);
        current = nextNode;
    }
    *head = sorted;
}

void append(Node **a, Node**b){
    Node *new = NULL;
    Node *current = *b;
    Node *next = NULL;
    while (current != NULL){
        next = current->next;
        push(&new, current);
        current = next;
    }
    *a = new;
    *b = NULL;
}

Node *RemoveDuplicates(Node *head){
    Node dummy;
    Node *current = &dummy;
    dummy.next = head;
    Node *nextNode = NULL;
    while (current->next != NULL){
        nextNode = current->next;
        if (current->data == nextNode->data){
            nextNode = nextNode->next;
            free(current->next);
            current->next = nextNode;
        }
        else {
            current = current->next;
        }
    }
    return dummy.next;
}

void MoveNode(Node **a, Node**b){
    Node *newNode = NULL;
    if (*b == NULL){
        assert(0);
    }
    Node *currentb = *b;
    newNode = currentb;
    *b = currentb->next;
    Node *currenta = *a;
    newNode->next = *a;
    *a = newNode;
    return;
}

void AlternatingSplit(Node* head, Node** aRef, Node** bRef) {
    Node *current = head;
    while (current != NULL){
        MoveNode(aRef, &current);
        if (current != NULL){
            MoveNode(bRef, &current);
        }
    }
    return;

}

Node *ShuffleMerge(Node *a, Node *b) {
    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;

    if (a == NULL || b == NULL){
        assert(0);
    }
    while (a != NULL || b != NULL){
        if (a != NULL){
            MoveNode(&(tail->next), &a);
            tail = tail->next;
        }
        else if (b != NULL){
            MoveNode(&(tail->next), &b);
            tail = tail->next;
        }
    }
    return dummy.next;
}

void FrontBackSplit(Node *test, Node **frontRef, Node **backRef){
    Node *slow = test;
    Node *fast = test;
    Node *prev = NULL;
    // if ((slow->next == NULL) || (slow == NULL)){
    //     assert(0);
    // }

    if (test == NULL || test->next == NULL){
        *frontRef = test;
        *backRef = NULL;
        return;
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

Node *SortedMerge(Node *a, Node *b) {
    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            MoveNode(&(tail->next), &a);
        } else {
            MoveNode(&(tail->next), &b);
        }
        tail = tail->next;
    }

    // Append the remaining nodes from the non-empty list
    if (a != NULL) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    return dummy.next;
}

void MergeSort(Node **head){
    Node *current = *head;
    Node *a;
    Node *b;
    if (current == NULL || current->next == NULL){
        return;
    }
    FrontBackSplit(current, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *head = SortedMerge(a, b);

}

Node *SortedIntersect(Node *a, Node *b){
    Node *intersect = NULL;
    intersect = SortedMerge(a, b);
    // intersect = RemoveDuplicates(intersect);
    // return intersect;
    Node dummy;
    dummy.next = intersect;
    Node *nextNode = &dummy;
    while (intersect->next != NULL){
        nextNode = intersect->next;
        if (intersect->data == nextNode->data){
            nextNode = nextNode->next;
            free(intersect->next);
            intersect->next = nextNode;
        }
        else {
            intersect = intersect->next;
        }
    }
    return dummy.next;
}

void *Reverse(Node **head){
    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;
    Node *current = *head;

    while (current != NULL){
        MoveNode(&(tail->next), &current);
    }
    *head = dummy.next;
    // Node *reversed = NULL;
    // Node *previous = NULL;
    // Node *current = *head;
    // while (current != NULL){
    //     push(&reversed, current);
    //     current = current->next;
    // //     previous = current;
    // //     current = current->next;
    // // }
    // // while (current->next != *head){
    // //     current->next = previous;
    // //     previous->next
    // // }
    // }


}

int main(){
    Node *myNode = BuildOneTwoThree();
    Node *a = DeckA();
    Node *b = DeckB();
    displayList(myNode);
    Reverse(&myNode);
    displayList(myNode);
    // Node *ret = NULL;
    // displayList(a);
    // displayList(b);
    // ret = SortedIntersect(a, b);
    // displayList(ret);
    // Node *merged = NULL;
    // displayList(myNode);
    // MergeSort(&myNode);
    // displayList(myNode);
    // merged = SortedMerge(a, b);
    // displayList(merged);
}