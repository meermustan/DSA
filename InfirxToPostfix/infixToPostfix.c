#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stack {
    int size;
    int top;
    char * arr;
};


char isFull(struct stack * ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }else{
        return 0;
    }
};

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
};

void push(struct stack * ptr, char value){
    if(isFull(ptr)){
        printf("The stack is full \n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
};

char pop(struct stack * sp){
    if(isEmpty(sp)){
        printf("Stack is empty\n");
        return -1;
    }else{
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
};

char stackTop(struct stack * sp){
    return sp->arr[sp->top];
    
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }else{
        return 0;
    }
};

int precedence(char value){
    if(value == '*' || value == '/'){
        return 3;
    }else if(value == '+' || value == '-'){
        return 1;
    }else{
        return 0;
    }
}

char * infixToPostfix(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char * postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0;
    int j = 0;

    while(infix[i] != '\0'){
      if(!isOperator(infix[i])){
        postfix[j] = infix[i];
        j++;
        i++;
      }
      else{
        if(precedence(infix[i]) > precedence(stackTop(sp)) ){
            push(sp, infix[i]);
            i++;
        }else{
            postfix[j] = pop(sp);
            j++;
        }
      }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
};

int main(){
    char * infix = "x-y/z-k*d";
    printf("postfix is %s\n", infixToPostfix(infix));
    return 1;
};