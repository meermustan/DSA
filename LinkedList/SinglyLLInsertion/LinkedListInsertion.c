#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void traversalLinkedList(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0; 
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertionAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != index -1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 88;
    head->next = second;



    second->data = 48;
    second->next = third;

    third->data = 27;
    third->next = NULL;

    printf("Initial state of Linked List: \n");
    traversalLinkedList(head);

    head = insertAtFirst(head, 44);

    printf("After insertion at first \n");
    traversalLinkedList(head);

    head = insertionAtIndex(head, 42, 2);

    printf("Insertion in b/w the index \n");
    traversalLinkedList(head);

    head = insertAtEnd(head,40);

    printf("After insertion at end \n");
    traversalLinkedList(head);
    
    head = insertAfterNode(head, third, 50);
    printf("Insertion after a Node \n");
    traversalLinkedList(head);

    return 0;
}