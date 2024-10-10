#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
    struct node* prev;
};

void Push(struct node **headref, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = *headref;
    if (*headref != NULL)
    {
        (*headref)->prev = newNode;
    }
    *headref = newNode;
}

struct node *Build() {
    struct node *head = NULL;
    // Push(&head, 1);
    // Push(&head, 2);
    // Push(&head, 4);

    return head;
}

void Display(struct node *head) {
    printf("NULL < - > ");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
        printf("< - > ");
    }
    printf("NULL\n");
}

struct node *Reverse(struct node **head)
{
    struct node *curr = *head;
    struct node *temp = NULL;
    if (*head==NULL)
    {
        return NULL;
    }
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if (temp != NULL)
    {
        *head = temp->prev;
    }
    return *head;
}

int main() {
    struct node *head = Build();
    Display(head);
    Reverse(&head);
    Display(head);
    return 0;
}
