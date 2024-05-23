#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
};

struct Node * traversal(struct Node * head){
    struct Node * p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != NULL);

    printf("\n");

    return 0;
}

struct Node * reverseTraversal(struct Node * last){
    struct Node * p = last;
    do{
        printf("%d ", p->data);
        p = p->prev;
    }while(p != NULL);
    
    printf("\n");

    return 0;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 48;
    head->next = second;

    second->prev = head;
    second->data = 58;
    second->next = third;

    third->prev = second;
    third->data = 29;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 15;
    fourth->next = NULL;

    traversal(head);

    printf("Traversal in reverse order\n");
    reverseTraversal(fourth);

    return 1;
};