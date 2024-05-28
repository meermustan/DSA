# Insertion in an Array

#### Description
In our array we are going to insert the value at a specific index.

### Approach
Simply we will start from last element of an array and comes backward with incrementing the elements to +1 position from their original positioin and when we reaches to our insertion index it's will already empty because we already moved our elements to next index.

### Code Walkthrough and explaination
Nesseary imports for the C
```c
#include  <stdio.h>
```

Traversal function:
```c
void  traversal(int  arr[], int  n){
	for (int  i  =  0; i  <  n; i++)
	{
		printf("%d  \t", arr[i]);
	}
	printf("\n");
}
```
In traversal function simply we are getting parameters of array of integers and size as n. So our loop runs till  the n numbers of times and print the value of array at every index.

```c
void  indexInsertion(int  arr[], int  element, int  index, int  capacity, int  size){
	if(size  >=  capacity){
		printf("Array is already full\n");
		return  -1;
	}

	for (int  i  =  size  -  1; i  >=  index; i--)
	{
		arr[i+1] =  arr[i];
	}
	arr[index] =  element;
	return  1;
}
```
In our `indexInsertion` function we are getting integers of array as `arr`, int of `elemnt` that we want to insert, int of `index` at which we want to insert, int max `capacity` of the array if already full then we are unable to store data, int of `size` it's used size.

So first  we check if we haven't used our full array space, and there is capacity to store our new element at index. so for that we did the if check `size  >=  capacity` simply saying if our used size is grater then or equals to capacity then we returns that array is full.

And if array is not full then
We runs a for loop that `i = size -1` means we will comes to last/max index as index starts from 0 so have to do -1, and after that to comes in a reverse order we will do `i--` and runs the for loop till `i  >=  index`  as our i is coming from max size index to backward till the index in which we have to insert so everytime it's does is `arr[i+1] =  arr[i]`  the i + 1 position equal to the current `arr[i]` so the element pushed to next index and when it's comes to our required index of insertion then outer of the for loop we did `arr[index] =  element;` so its updated the value at that index to our element.

**Assume we have to insert at index 2 with element value 45 then and array size is 4**
Then i of our loop initially becomes `size -1` means `4-1` which is `3`, and yes if size is `4` then if we start index count from `0` it's only get's to `3` which is right value, After that in our for loop condition it's runs till our i that was `3` is greater then and equals to our insertion index and while the condition is true then it's updates the value of `arr[i + 1] = arr[i]` assume for first loop cycle then the i is 3 so `arr[3+1]` means `arr[4] = arr[3]` the arry value at index 4 becomes equal to arr value at index 3 and we are doing `i--` so the loop goes backwards till the insertion index. 
After increment one step next each index of array till insertion index we finally at the required index inserts our value `arr[index] =  element` means `arr[2] = 4` so array index 2 value becomes 4 and ends the insertion.

here is how our main function looks like:
```c
int  main(){
	int  arr[100] = {10, 24, 8 , 32};
	int  size  =  4;
	int  capacity  =  100;
	int  element  =  45, index  =  2;
	traversal(arr, size);
	indexInsertion(arr, element, index, capacity, size);
	size  =  size+1;
	traversal(arr, size);
}
```
That it simply we assigning 100 size of array and first traversal before the insertion and after insertion changes size to size + 1 and agian runs the traversal.

