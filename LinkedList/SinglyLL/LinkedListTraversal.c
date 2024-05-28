#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node * next;
};

void linkListTraversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    return 1;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 8;
    head->next = second;

    second->data = 66;
    second->next = third;
    
    third->data = 24;
    third->next = NULL;

    linkListTraversal(head);
    return 0;
}