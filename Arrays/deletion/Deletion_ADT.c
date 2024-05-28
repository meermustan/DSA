#include <stdio.h>

void traversal(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void IndexDeletion(int arr[], int index, int size){
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    return 1;
    
}

int main(){
    int arr[100] = {20, 30, 80, 60, 10};
    int size = 5;
    int capacity = 100;
    int index = 1;
    traversal(arr, size);
    IndexDeletion(arr, index, size);
    size = size - 1;
    traversal(arr, size);
}