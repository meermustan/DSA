#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr ;
};

void createArray(struct myArray* a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize*sizeof(int));

    // can also written as:
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize*sizeof(int));
};

void setVal(struct myArray* a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d value : ", i);
        scanf("%d", &n);
        printf("\n");
        (a->ptr)[i] = n;
    }
    
}

void showValue(struct myArray* a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Your element %d value is %d \n",i, (a->ptr)[i]);
    }
    
}

int main(){
    struct myArray marks;
    createArray(&marks, 100, 2);
    printf("Running set values \n");
    setVal(&marks);
    printf("Running show values \n");
    showValue(&marks);
    printf("Our used size is %d/%d \n",((&marks)->used_size), ((&marks)->total_size));
    return 0;
};

