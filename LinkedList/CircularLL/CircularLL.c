#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * traversl(struct Node * head){
    // struct Node * head = head;
    struct Node * ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf(" \n");
    return 0;
}

struct Node * insertionAtFirst(struct Node * head, int data){
    struct Node * p = head;
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}

struct Node * insertionAtIndex(struct Node * head, int index, int data){
    struct Node * q = head;
    struct Node * p = head->next;
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    };
    q->next = ptr;
    ptr->next = p;
    
    return head;
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

    head->data = 48;
    head->next = second;

    second->data = 85;
    second->next = third;

    third->data = 38;
    third->next = fourth;

    fourth->data = 29;
    fourth->next = head;

    printf("Initial traversal of Node \n");
    traversl(head);


    head = insertionAtFirst(head, 27);
    printf("The traversal after insertion at First Node \n");
    traversl(head);

    head = insertionAtIndex(head, 1, 10);
    printf("The traversal after insertion at Index \n");
    traversl(head);

    return 1;
}; 