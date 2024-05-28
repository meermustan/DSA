#include <stdio.h>

void traversal(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void indexInsertion(int arr[], int element, int index, int capacity, int size){
    if(size >= capacity){
        printf("Array is already full\n");
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i+1] = arr[i]; 
    }
    arr[index] = element;
    return 1;
}

int main(){
    int arr[100] = {10, 24, 8 , 32};
    int size = 4;
    int capacity = 100;
    int element = 45, index = 2;
    traversal(arr, size);
    indexInsertion(arr, element, index, capacity, size);
    size = size+1;
    traversal(arr, size);
}