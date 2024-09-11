// 92. Reverse Linked List II

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node;

 // sub problem: partition the list

Node *BuildList()
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    Node *list = (Node*)malloc(sizeof(Node));
    Node *curr = list;
    curr->next = NULL;
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            curr->val = arr[i];
        }
        else {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->val = arr[i];
            curr->next  = newNode;
            curr = newNode;
        }
    }
    curr->next = NULL;
    return list;
}

void display(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *curr = head;
    Node *store = NULL;
    while (curr->next)
    {
        store = curr->next;
        free(curr);
        curr = store;
    }
}

// left = 2 and right = 4

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *nextNode = NULL;
    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node *reverseBetween1(Node *head, int left, int right)
{
    Node dummy;
    dummy.next = head;
    Node *curr = &dummy;
    Node *prev = NULL;
    int i = 1;
    while (i <= left)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    Node *partHead = prev;
    Node *partTail = curr;

    Node *partition = NULL;

    while (i <= right)
    {  
        prev = curr;
        curr = curr->next;
        i++;
    }
    Node *store = curr->next;
    curr->next = NULL;

    Node *rev = reverse(partTail);
    partHead->next = rev;
    partTail->next = store;
    return dummy.next;
    
}

Node *reverseBetween(Node *head, int left, int right)
{
    Node dummy;
    dummy.next = head;
    Node *store = NULL;
    Node *prev = &dummy;
    Node *curr = head;

    for (int i = 1; i < left; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    Node *partHead = prev;
    Node *partTail = curr;

    
    for (int i = left; i <= right; i++)
    {
        store = curr->next;
        curr->next = prev;
        prev = curr;
        curr = store;
    }
    partHead->next = prev;
    partTail->next = curr;
    return dummy.next;
}

int main()
{
    Node *head = BuildList();
    display(head);
    Node *ret = reverseBetween1(head, 2, 4);
    display(ret);
}