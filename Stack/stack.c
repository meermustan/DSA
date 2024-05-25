#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;

};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
};

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        printf("Stack is full\n");
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack * ptr, int data){
    if(isFull(ptr)){
        printf("Stack is full\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
        return 1;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
    }else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        ptr->arr[ptr->top + 1] = 0; // free the value by providing zero value
        return value;
    }
}

void traversal(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
        return 0;
    }
    int i = 0;
    while(i <= ptr->top){
        printf("%d  ", ptr->arr[i]);
        i++;
    }
    printf("\n");
    return 1;
}

int peek(struct stack * ptr, int i){
    int arrayIndex = ptr->top -i + 1;
    if(arrayIndex < 0){
        printf("Not valid position in stack\n");
    }else{
        return ptr->arr[arrayIndex];
    }
}

int stackTop(struct stack * ptr){
    if(ptr->top >= 0){
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct stack * ptr){
    if(ptr->top >= 0){
        return ptr->arr[0];
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    // struct stack s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 30);
    push(s, 80);
    push(s, 28);

    
    
    for (int j = 1; j <= (s->top + 1) ; j++)
    {
        printf("The value at position %d is %d \n", j,peek(s, j));
    }

    printf("The stack top is %d \n", stackTop(s));
    printf("The stack bottom is %d \n", stackBottom(s));
    

    if(isEmpty(s)){
        printf("Stack is empty \n");
    }

    return 1;
};