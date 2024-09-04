#include <stdio.h>

// Function to remove odd numbers from the array
void without_odds(int *arr, int *len) {
    int j = 0; // Index for the compacted array

    // Iterate through the array
    for (int i = 0; i < *len; i++) {
        if (arr[i] % 2 == 0) { // Check if the number is even
            arr[j++] = arr[i]; // Copy the even number to the new position
        }
    }

    *len = j; // Update the length to reflect the number of even elements
}

int main() {
    int arr[] = {1, 2, 5}; // Original array
    int len = sizeof(arr) / sizeof(arr[0]); // Number of elements in the array

    without_odds(arr, &len); // Remove odd numbers

    // Print the modified array
    printf("Array after removing odd numbers: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
