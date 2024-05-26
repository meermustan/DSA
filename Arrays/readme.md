# Array in C

#### Description
Crating an array in C is although very simple we can allocate an array through dynamic memory allocation but here we are going to allocate the array through the structure so that using of structure become use to when in near future we use the structure.
```c
#include<stdio.h>
#include<stdlib.h>
```
These are important imports so that we can use the c basics and structure.

Now first of all we assign a struct of an array.
```c
struct  myArray {
	int total_size;
	int used_size;
	int *ptr ;
};
``` 
we created a structure which get's three values, one is `total_size	` the size of our array, second is `used_size` the size which we have used, and the last and third thing is `ptr` the pointer where we allocated our memory for our array.

Now let's assign the array and it's values using our structure.
```c
void  createArray(struct  myArray*  a, int  tSize, int  uSize){
		// (*a).total_size = tSize;
		// (*a).used_size = uSize;
		// (*a).ptr = (int *)malloc(tSize*sizeof(int));

	  // can also written as:
		a->total_size  =  tSize;
		a->used_size  =  uSize;
		a->ptr  = (int  *)malloc(tSize*sizeof(int));

};
```

here in `createArray` function we are creating our array, yep allocating our array in memory with used size and total size. and our function requires three parameters, `myArray` the struct of myArray as a, `tSize` total size of array and `uSize` used size of an array.

Now to run code and for final creation of our array Using main function.
```c
int  main(){
	struct  myArray  marks;
	createArray(&marks, 100, 2);
	return  0;
};

```
Here in main function we are using `myArray` structure and assign it with veriable marks, after that have to run a function `createArray` to actually create an array, so that in createArray function while we are calling it giving it params. `&marks` the address of marks veriable, `100` the total size of array and `2` the used size of array.


