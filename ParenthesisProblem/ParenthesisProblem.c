#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char * arr;
};

char isFull(struct stack * sp){
    if(sp->top + 1 >= sp->size){
        return 1;
    }else{
        return 0;
    }
};

void push(struct stack * sp, char value){
    if(isFull(sp)){
        printf("The stack is full \n");
    }else{
        sp->top++;
        sp->arr[sp->top] = value;
    }
};

int isEmpty(struct stack * sp){
    if(sp->top == -1){
        return 1;
    }else{
        return 0;
    }
};

char stackTop(struct stack * sp){
    return sp->arr[sp->top];
}


char pop(struct stack * sp){
    if(isEmpty(sp)){
        return 0;
    }else{
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
};

int match(char a, char b){
    if(a == '{' && b == '}'){
        return 1;
    }else if( a == '(' && b == ')' ){
        return 1;
    }else if( a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int parenthesisProblem(char *exp){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (char i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '('){
            push(sp,'(');
        }else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    
    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }
};

int multipleParenthesisProblem(char *exp){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (char i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(sp, exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){
                return 0;
            }
        }
    }
    
    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }
};


int main(){
    char * exp = "[4-5]({8}*{(24[-]1)})";
    if(multipleParenthesisProblem(exp)){
        printf("Parenthesis are balanced\n");
    }else{
        printf("Parenthesis are not balanced\n");
    }
    return 1;
};