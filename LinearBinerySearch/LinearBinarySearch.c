#include <stdio.h>
#include <math.h>

int LinearSearch(int arr[], int size, int element){
    int i = 0;
    while (i < size)
    {
        if (arr[i] == element)
        {
            printf("The element %d is found at index %d\n", element, i);
            return 1;
        }
        i++;
    };
    printf("Element not found in array \n");
    return -1;
}

int BinarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size -1 ;

    while(low <= high){
        mid = floor((low + high)/ 2); 
        if(arr[mid] == element){
            return mid;
        }
        else if(arr[mid] > element){
            high = mid - 1;
        }
        else if(arr[mid] < element){
            low = mid + 1;
        }
    }
    return -1;
}


int main(){
    // Linear Search for unsorted elements
    int arr[100] = {2, 8, 22, 6 , 18, 45, 100};
    int size = 7;
    LinearSearch(arr, size, 22);
    
    // Binary search for sorted elements
    int sortedArr[100] = {2, 6, 7, 8, 10, 52, 58, 72, 99, 100, 400, 500, 600};
    int sortedSize = 13;
    int BinarySearchIndex = BinarySearch(sortedArr, sortedSize, 2);
    printf("The element %d is found at index %d \n", 2, BinarySearchIndex);
}