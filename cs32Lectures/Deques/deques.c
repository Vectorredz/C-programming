#include <stdio.h>
#include <stdlib.h>

#define n 12  // Maximum size of deque

typedef int DequeElemType;

typedef struct deque {
    int left;
    int right;
    DequeElemType *Deck;
} Deque;

void InitDeque(Deque *D) {
    D->left = -1; 
    D->right = -1; 
    D->Deck = (DequeElemType*)malloc(n * sizeof(DequeElemType)); 
}

void EnqueueRight(Deque *D, DequeElemType x) {
    if (D->right == n - 1) return; // Deque is full
    if (D->right == -1 && D->left == -1){
        D->right = 0;
        D->left = 0;
    }
    else {
        D->right++;
    }
    D->Deck[D->right] = x;
}

void DequeueLeft(Deque *D, DequeElemType *x) {
    if (D->left < 0) return; // Check if empty
    *x = D->Deck[D->left];
    D->left++;
    if (D->left > D->right){
        D->left = D->right = -1;
    }
}

void DequeueRight(Deque *D, DequeElemType *x) {
    if (D->right < 0) return; // Check if empty
    *x = D->Deck[D->right];
    D->right--;
    if (D->left > D->right){
        D->left = D->right = -1;
    }
}

int* maxSlidingWindow(int* nums, int size, int k, int* returnSize) {
    Deque D;
    InitDeque(&D); 
    DequeElemType x;
    
    // Result size based on the number of sliding windows
    *returnSize = size - k + 1; 
    int* result = (int*)malloc((*returnSize) * sizeof(int)); 
    int resultIndex = 0;

    for (int i = 0; i < size; i++) {
        // Remove elements out of the current window (left side)
        if (D.left != -1 && D.Deck[D.left] <= i - k) {
            DequeueLeft(&D, &x);
        }

        // Remove elements smaller than the current element (right side)
        while (D.right != -1 && nums[D.Deck[D.right]] < nums[i]) {
            DequeueRight(&D, &x);
        }

        // Add current element index to deque
        EnqueueRight(&D, i);

        // If window has hit size k, record the maximum
        if (i >= k - 1) {
            result[resultIndex++] = nums[D.Deck[D.left]]; // The front of the deque is the max
        }
    }
    return result;
}

int main() {
    int list[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int size = sizeof(list) / sizeof(list[0]);

    int returnSize; // Variable to hold the size of the result array
    int k = 3;
    int *ret = maxSlidingWindow(list, size, k, &returnSize); // Pass address of returnSize

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");

    free(ret); // Free the allocated memory for the result

    return 0;
}
