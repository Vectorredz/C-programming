#include <stdio.h>
#include <stdlib.h>
#define n 101

typedef struct binaryNode binaryNode;
struct binaryNode {
    int data;
    struct binaryNode* left;
    struct binaryNode* right;
};

// Auxiliary functions


void display(binaryNode *root){
    if (root == NULL){
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

binaryNode *newNode(int data){
    binaryNode *newnode = (binaryNode*)malloc(sizeof(binaryNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

//  1. Build123

binaryNode *build123(){
    binaryNode *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    return root;
}

// 2. Insert

binaryNode *insert(binaryNode *root, int data){
    if (root == NULL){
        root = newNode(data);
        return root;
    } 
    if (root->data <= data) {
        return insert(root->right, data);
    } 
    else {
        return insert(root->left, data);
    }
    return root;
}

// 3. Size

int size(binaryNode *root){
    if (root == NULL){
        return 0;
    }
    else {
        return 1 + size(root->left) + size(root->right);
    }
}

// 4. MaxDepth

int maxDepth(binaryNode *root){
    if (root == NULL){
        return 0;
    }
    else {
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
}

// 5. MinValue of a binary tree | 5.1 MinValue of a tree

int minValue(binaryNode *root){
    if (root->left == NULL){
        return root->data;
    }
    else {
        return minValue(root->left);
    }

}

int minTree(binaryNode *root, int retMin, int currMin){
    if (root == NULL) return retMin;
    currMin = root->data;

    if (currMin < retMin){
        retMin = currMin;
    }
    retMin = minTree(root->left, retMin, root->data);
    retMin = minTree(root->right, retMin, root->data);

    return retMin;
}

int helper(binaryNode *root){
    if (root == NULL) return 0;
    return minTree(root, root->data, root->data);
}

// 6. printTree

void printTree(binaryNode *root){
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// 7. printPostorder

void printPostorder(binaryNode *root){
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

// 8. printPaths

void printArray(int ints[], int len);
// void printPathsRecur(binaryNode* node, int path[], int pathLen);

// void printPaths(binaryNode* node) {
//     int *paths = (int*)malloc(n * sizeof(int));
//     printPathsRecur(node, paths, 0);
// }

// void printPathsRecur(binaryNode* node, int path[], int pathLen) {
//     if (node==NULL) return;

//     path[pathLen] = node->data;
//     pathLen++;

//     if (node->left==NULL && node->right==NULL) {
//         printArray(path, pathLen);
//     }
//     else {
//         printPathsRecur(node->left, path, pathLen);
//         printPathsRecur(node->right, path, pathLen);
//     }
// }
// void printArray(int ints[], int len) {
//     int i;
//     for (i=0; i<len; i++) {
//         printf("%d ", ints[i]);
//     }
//         printf("\n");
//     }

// // 9. binarySum

// int sum(binaryNode *root){
//     if (root == NULL){
//         return 0;
//     }
//     else {
//         return root->data + sum(root->right) + sum(root->left);
//     }
// }

// // 10. sumOfPaths

// void pprint(binaryNode *root){
//     int *paths = (int*)malloc(n * sizeof(int));
//     if (root == NULL) return;
//     pathSum(root, 9, 0);
// }

// // 11. Mirror 

void mirror(binaryNode *root){
    if (root ==  NULL){
        return;
    }
    else {
        binaryNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        mirror(root->right);
        mirror(root->left);
    }
    return;
    /*
    
    */
}

// 12. DoubleTree

void DoubleTree(binaryNode *node){
    if (node == NULL){
        return;
    }
    // track the node   
    binaryNode * old_left = node->left;
    binaryNode *new_left = newNode(node->data);
    node->left = new_left;
    new_left->left = old_left;

    DoubleTree(old_left);
    DoubleTree(node->right);
    return;
}

// 13. sameTree

int isSame(binaryNode* uno, binaryNode* tres) {
    if (uno == NULL && tres == NULL) {
        return 1;
    } else if (uno != NULL && tres != NULL) {
        return (uno->data == tres->data) && isSame(uno->left, tres->left) && isSame(uno->right, tres->right);
    }
    return 0;
}

// 14. delete

void delete(binaryNode *root, int value){
    if (root == NULL){
        return;
    }
    else {
        if (root->left->data == value){
            
        }
    }
}


// int pathSum(binaryNode *root, int sum, int *paths, int len){
//     if (root == NULL){
//         return 0;
//     }

//     paths[len] = root->data;
//     len++;

//     if (sum==0){
//         return 
//     }
//     else {
//         pathSum(root,)
//     }
// }


int main(){
    binaryNode *head = build123();
    binaryNode *head1 = build123();
    display(head);
    delete(head, 3);
    display(head);
}
