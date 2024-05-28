# Deletion in an Array

#### Description
In our array we are going to delete the value at a specific index.

### Approach
Simply we set our deletion index equal to loop initial index and changes the values of current index with it's next index value and do it till the last element of the array and at end decrease the size of the array.

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
void  IndexDeletion(int  arr[], int  index, int  size){
	for (int  i  =  index; i  <  size; i++)
	{
		arr[i] =  arr[i+1];
	}
	return  1;
}
```
In our `indexDeletion` function we are getting integers of array as `arr`, int of `index` at which we want to delete and int of `size` it's used size.

We runs a for loop that `i = index` means we initially set our i value equal to index value and runs the for loop till `i  <  size`  runs till the end size of the array and every time increment the i by 1 through `i++`  and In loop everytime it's does is `arr[i] =  arr[i+1]`  the current index of array becomes equal to the array value at `i + 1` so its updates the each and every value after the index to fill up the space.

**Assume we have to delete at index 1 and array size is 5**
Then i of our loop initially becomes equals to index `1` , After that in our for loop condition it's runs till our i that was `1` is less then the size of the array (which is `5`) and increment i by 1 each time, and while the condition is true then it's updates the value of `arr[i] = arr[i+1]` assume for first loop cycle the value of i is 1 then  `arr[i] = arr[i+1]` means `arr[1] = arr[2]` the arry value at index 1 becomes equal to arr value at index 2 and so on till end and we are doing `i++` so the loop goes till the end size of the array. 

here is how our main function looks like:
```c
int  main(){
	int  arr[100] = {20, 30, 80, 60, 10};
	int  size  =  5;
	int  capacity  =  100;
	int  index  =  1;
	traversal(arr, size);
	IndexDeletion(arr, index, size);
	size  =  size  -  1;
	traversal(arr, size);
}
```
That it simply we assigning 100 size of array and first traversal before the deletion and after deletion changes the size to size -1 and agian runs the traversal.

