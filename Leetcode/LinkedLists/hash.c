// 705. Design HashSet

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




typedef struct MyHashSet{
    int *arr;
    int size;
    int capacity;
} hash;


hash* myHashSetCreate() {
    hash *obj = (hash*)malloc(sizeof(hash));
    obj->size = 0;
    obj->capacity = 10;
    obj->arr = (int*)malloc(obj->capacity * sizeof(int));

    return obj;
}

void myHashSetAdd(hash* obj, int key) {
    if (obj->size >= obj->capacity){
        obj->capacity *= 2;
        obj->arr = (int*)realloc(obj->arr, obj->capacity * (sizeof(int)));
    }
    obj->arr[obj->size++] = key;
    return;
}

void myHashSetRemove(hash* obj, int key) {
    int *copyarr = (int*)malloc(obj->size * sizeof(int));
    int newSize = 0;
    for (int i = 0; i < obj->size; i++){
        if (obj->arr[i] != key){
            copyarr[newSize++] = obj->arr[i];
        }
    }
    free(obj->arr);
    obj->arr = copyarr;
    obj->size = newSize;
}

bool myHashSetContains(hash* obj, int key) {
    for (int i = 0; i < obj->size; i++){
        if (obj->arr[i] == key){
            return true;
        }
    }
    return false;
}

void myHashSetFree(hash* obj) {
    free(obj->arr);
}

void displayHash(hash *obj){
    int i = 0;
    printf("{");
    while (i < obj->size){
        printf("%d,", obj->arr[i]);
        i++;
    }
    printf("}\n");

}

int main(){
    hash *obj = myHashSetCreate();
    int key = 2;
    myHashSetAdd(obj, key);
    key = 0;
    myHashSetAdd(obj, key);
    int ret = myHashSetContains(obj, 3);
    printf("%d ", ret);

    // key = 2;
    // myHashSetRemove(obj, key);
    // key = 3;
    // myHashSetRemove(obj, key);
    // displayHash(obj);


}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/