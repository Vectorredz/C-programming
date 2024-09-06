#include <stdio.h>

// Function to insert an element into a sorted array
void insert(int elem, int *sorted_elems, int *len){
    // Base case: If array is empty or we have processed all elements
    if (*len == 0 || elem >= sorted_elems[*len - 1]) {
        sorted_elems[*len] = elem;  // Place element at the correct position
        (*len)++;                   // Increment length to include the new element
        return;
    }

    // Recursive case: Shift elements and find the correct place to insert
    sorted_elems[*len] = sorted_elems[*len - 1];  // Shift the element
    (*len)--;                                     // Decrease the length
    insert(elem, sorted_elems, len);              // Recur to find correct position
    (*len)++;                                     // Restore the length after insertion
}

int main(){
    int sorted_elems[4] = {10, 20, 30};  // Array with space for one more element
    int elem = 5;
    int len = 3;  // Current number of elements in the array
    
    insert(elem, sorted_elems, &len);  // Insert the element
    
    // Print the array
    for (int i = 0; i < len; i++){
        printf("%d ", sorted_elems[i]);
    }
    
    return 0;
}
