#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * top = NULL;

void linkListTraversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    return 1;
};

int isEmpty(struct Node * top){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
};

int isFull(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }else{
        return 0;
    }
};

struct Node * push(struct Node * top, int x){
    if(isFull(top)){
        printf("Stack is full.\n");
    }else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
};

int peek(int pos){
    struct Node * ptr = top;
    for (int i = 0;(i < pos -1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }else{
        return -1;
    }
    
}

int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack is empty.\n");
    }else{
        struct Node * n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
};

int stackTop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack is empty.\n");
    }else{
        return top->data;
    }
};

int stackBottom(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack is empty.\n");
    }else{
     struct Node * n = tp;
     while(n->next != NULL){
        n = n->next;
     }
     return n->data;
    }
}

int main(){
    top = push(top, 38);
    top = push(top, 29);
    top = push(top, 27);
    top = push(top, 79);
    top = push(top, 74);
    top = push(top, 68);
    linkListTraversal(top);
    printf("The popped value is %d\n", pop(top));
    linkListTraversal(top);
    printf("The peek value is %d\n", peek(2));
    
    printf("The stack top is %d\n", stackTop(top));

    printf("The stack bottom is %d\n", stackBottom(top));

    return 1;
};