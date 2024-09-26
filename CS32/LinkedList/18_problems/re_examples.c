// build lists

#include <stdio.h>
#include <stdlib.h>
#include "buildLists.h"
#include <assert.h>

Node *BuildLL(){
    // int arr[] = {1,2,3,4,5};
    int arr[] = {3,10,2,1,20};
    int len = sizeof(arr) / sizeof(arr[0]);
    Node *lists = (Node*)malloc(sizeof(Node));

    Node *curr = lists;
    curr->next = NULL;

    if (len == 0)
    {
        lists = NULL;
        return lists;
    }

    else 
    {
        for (int i = 0; i < len; i++){
            if (i == 0)
            {
                curr->val = arr[i];
            }
            else 
            {
                Node *node = (Node*)malloc(sizeof(Node));
                node->val = arr[i];
                curr->next = node;
                curr = node;
            }
        }
        curr->next = NULL;
        return lists;
    }
}

Node *BuildA(){
    // int arr[] = {1,2,3,4,5};
    int arr[] = {3,2,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    Node *lists = (Node*)malloc(sizeof(Node));

    Node *curr = lists;
    curr->next = NULL;

    if (len == 0)
    {
        lists = NULL;
        return lists;
    }

    else 
    {
        for (int i = 0; i < len; i++){
            if (i == 0)
            {
                curr->val = arr[i];
            }
            else 
            {
                Node *node = (Node*)malloc(sizeof(Node));
                node->val = arr[i];
                curr->next = node;
                curr = node;
            }
        }
        curr->next = NULL;
        return lists;
    }
}

Node *BuildB(){
    // int arr[] = {1,2,3,4,5};
    int arr[] = {1,3,5,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    Node *lists = (Node*)malloc(sizeof(Node));

    Node *curr = lists;
    curr->next = NULL;

    if (len == 0)
    {
        lists = NULL;
        return lists;
    }

    else 
    {
        for (int i = 0; i < len; i++){
            if (i == 0)
            {
                curr->val = arr[i];
            }
            else 
            {
                Node *node = (Node*)malloc(sizeof(Node));
                node->val = arr[i];
                curr->next = node;
                curr = node;
            }
        }
        curr->next = NULL;
        return lists;
    }
}

void display(Node *head){
    while (head != NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Utility Function: Push, Free, Length

void Push(Node **headref, int newVal)
{
    Node dummy;
    Node *curr = &dummy;
    dummy.next = *headref;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = newVal;
    newNode->next = curr->next;
    curr->next = newNode;
    *headref = dummy.next;
}

void Free(Node *head)
{
    Node *curr = head;
    Node *store = NULL;
    while (curr){
        store = curr->next;
        free(curr);
        curr = store;
    }
}

int Length(Node *head)
{
    int count = 0;
    while (head){
        count++;
        head = head->next;
    }
    return count;
}

int Count(Node *head, int searchFor)
{
    Node *curr = head;
    int count = 0;
    while (curr->next)
    {
        if (curr->val == searchFor)
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

int GetNth(Node *head, int index)
{
    int i = 0;
    Node *curr = head;
    while (curr->next != NULL){
        if (i == index)
        {
            return curr->val;
        }
        else 
        {
            curr = curr->next;
            i++;
        }
    }
    if (index > i){
        assert(0);
    }
}

void DeleteList(Node **head)
{
    Node *curr = *head;
    Node *store = NULL;
    while (curr->next)
    {
        store = curr->next;
        free(curr);
        curr = store;
    }
    *head = NULL;
}

int Pop(Node **head)
{
    Node *curr = *head;
    Node *store = NULL;
    int popped = 0;
    if (*head == NULL){
        assert(0);
    }

    store = curr->next;
    curr->next = NULL;
    popped = curr->val;
    free(curr);

    *head = store;
    return popped;
}

void InsertNth(Node **head, int index, int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *curr = *head;
    Node *nextNode = NULL;
    newNode->val = data;
    newNode->next = NULL;
    int i = 0;
    if (*head == NULL)
    {
        newNode->next = curr;
        *head = newNode;
    }
    while (curr != NULL){
        nextNode = curr->next;
        if (i == index)
        {
            curr->next = newNode;
            newNode->next = nextNode;
        }
        curr = curr->next;
        i++;
    }
    

    

}

void SortedInsert(Node  **headRef, Node *newNode)
{
    Node dummy;
    Node *curr = &dummy;
    Node *nexter = NULL;
    dummy.next = *headRef;
    if (*headRef == NULL)
    {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    if ((*headRef)->val >= newNode->val)
    {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    while (curr->next != NULL)
    {   
        nexter = curr->next;
        if (nexter->val >= newNode->val)
        {
            curr->next = newNode;
            newNode->next = nexter;
            break;
        }
        curr = curr->next;
    }
    if (curr->val >= nexter->val)
    {
        curr->next = newNode;
        newNode->next = NULL;
    }
    *headRef = dummy.next;

}

void InsertSort(Node **headRef)
{
    Node *sorted = NULL;
    Node *curr = *headRef;
    Node *nextNode = NULL;
    if (!(*headRef))
    {
        assert(0);
    }
    while (curr)
    {
        nextNode = curr->next;
        SortedInsert(&sorted, curr);
        curr = nextNode;
    }
    *headRef = sorted;
}

void Append(Node** aRef, Node** bRef)
{
    Node *currA = *aRef;
    Node *headB = *bRef;
    if (*aRef == NULL) // if a is empty
    {
        *aRef = *bRef;
        return;
    }
    while (currA->next)
    {
        currA = currA->next;
    }
    currA->next = headB;
    (*aRef)->next = currA;
    return;
}

void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    int len = Length(source);
    Node *slow = source;
    Node *fast = source;
    Node *prev = NULL;

    if (!(source))
    {
        *frontRef = NULL;
        *backRef = NULL;
        return;
    }
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (len % 2 == 0)
    {
        *backRef = slow;
        prev->next = NULL;
        *frontRef = source;
    }
    else 
    {
        *backRef = slow->next;
        slow->next = NULL;
        *frontRef = source;
    }
}

void RemoveDuplicates(Node **head)
{
    Node dummy;
    dummy.next = *head;
    Node *curr = &dummy;
    Node *store = NULL;
    
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->val == curr->next->val)
        {
            store = curr->next->next;
            free(curr->next);
            curr->next = store;
        }
        else
        {
            curr = curr->next;
        }
    }
    *head = dummy.next;
}

void MoveNode(Node **destRef, Node **sourceRef)
{
    Node *headB = *sourceRef;
    Node *headA = *destRef;
    Node *store = NULL;
    if (headB == NULL)
    {
        assert(0);
    }
    store = headB->next;
    headB->next = NULL;
    headB->next = headA;
    *destRef = headB;
    *sourceRef = store;
    return;
}

void AlternatingSplit(Node *source, Node **aRef, Node **bRef)
{
    Node *curr = source;
    Node *nextNode = NULL;

    if (curr == NULL){
        assert(0);
    }
    while (curr && curr->next)
    {
        nextNode = curr->next; // store the nextnode
        MoveNode(aRef, &curr);
        curr = nextNode; // traverse list
        nextNode = curr->next;
        MoveNode(bRef, &curr);
        curr = nextNode;
    }
    if (curr){ // if there is still existing node append it to the first list
        MoveNode(aRef, &curr);
    }
    else{
        return;
    }
}

Node *ShuffleMerge(Node *a, Node *b) 
{
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
        if (b != NULL){
            MoveNode(&(tail->next), &b);
            tail = tail->next;
        }
    }
    return dummy.next;
}

Node *SortedMerge(Node *a, Node *b)
{
    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;

    while (a && b)
    {
        if (b && (a->val > b->val ))
        {
            MoveNode(&(tail->next), &b);
            tail = tail->next;
        }
        else if (a && (a->val < b->val))
        {
            MoveNode(&(tail->next), &a);
            tail = tail->next;
        }
    }
    if (b)
    {
        tail->next = b;
    }
    else if (a)
    {
        tail->next = a;
    }

    return dummy.next;
}

Node *RecursiveMerge(Node *a, Node *b)
{
    if (!(a))
    {
        return b;
    }
    if (!(b))
    {
        return a;
    }
    else {
        if (a->val > b->val)
        {
            b->next = RecursiveMerge(a , b->next);
            return b;
        }
        else if (a->val < b->val)
        {
            a->next = RecursiveMerge(a->next , b);
            return a;
        }
    }
}

void MergeSort(Node **headref)
{
    Node *head = *headref;
    Node *a = NULL;
    Node *b = NULL;
    if (!(head->next)) return;
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    head =  SortedMerge(a, b);
    *headref = head;
}

Node *SortedIntersect(Node *A, Node *B)
{   
    while (A->val != B->val)
    {
        A = A ? A->next : B;
        B = B ? B->next : A;
    }
    return A;
}

void Reverse(Node **headref)
{
    Node dummy;
    dummy.next = NULL;
    Node *tail = &dummy;
    Node *current = *headref;

    while (current)
    {   
        MoveNode(&(tail->next), &current);
    }
    

    *headref = dummy.next;

}

void Reverse_3(Node **headref)
{
    Node *curr = *headref;
    Node *prev = NULL;
    Node *nextNode = NULL;
    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    *headref = prev;
}

// void reverseDisplay(Node *head)
// {
//     if (head == NULL)
//     {
//         printf("NULL -> ");
//         return;
//     }
//     reverseDisplay(head->next);
//     printf("%d -> ", head->val);
// }
void Reversed(Node *curr, Node *prev, Node **headref)
{
    if (!(curr))
    {
        *headref = prev;
        return;
    }
    else 
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        Reversed(nextNode, curr, headref);
    }

}
void RecursiveReverse(Node **headref)
{
    Reversed(*headref, NULL, headref);
}


//counting problems

void insert_end(Node **head, Node *val){
    if (*head == NULL)
    {
        *head = val;
    }
    Node *current = *head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = val;
    return;
}


Node *LongestIncreasingSubsequence(Node *head)
{
    Node *curr = head->next;
    Node *prev = head;
    Node *store = NULL;
    Node *empty = (Node*)malloc(sizeof(Node));

    insert_end(&empty, curr);
    
    return empty;

    
    
}
    



int main(){
    Node *head = BuildLL();
    Node *A = BuildA();
    Node *B = BuildB();
    display(head);
    Node* ret = LongestIncreasingSubsequence(head);
    display(ret);  

    

    
}