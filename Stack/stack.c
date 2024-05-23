#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;

};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        printf("Stack is empty\n");
        return 1;
    }else{
        return 0;
    }
};

int isFull(struct stack* ptr){
    if(ptr->size >= ptr->top + 1){
        printf("Stack is full\n");
        return 1;
    }else{
        return 0;
    }
}

int main(){
     struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    // struct stack s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    isEmpty(s);
    return 1;
};