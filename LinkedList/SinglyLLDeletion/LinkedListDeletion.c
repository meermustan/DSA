#include <stdio.h>
#include <stdlib.h>

struct Node {
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

struct Node * deleteFirstNode(struct Node * head){
    // struct Node * p = head->next;
    // return head;
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    if(index == 0){
        head = deleteFirstNode(head);
        return head;
    }
    struct Node * p = head;
    int i = 0;
    while (i != index -1 )
    {
       p = p->next;
       i++;
    }
    struct Node * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteLastNode(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteAtValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    if(p->data == value){
        head = deleteFirstNode(head);
        return head;
    }
    while (q->data != value && q->next != NULL)
    {   
        q = q->next;
        p = p->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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

    head->data = 99;
    head->next = second;

    second->data = 48;
    second->next = third;

    third->data = 42;
    third->next = fourth;

    fourth->data = 27;
    fourth->next = NULL;

    printf("Initial state of Linked List: \n");
    traversalLinkedList(head);

    // head = deleteFirstNode(head);
    // printf("After deletion of first element \n");
    // traversalLinkedList(head);

    // head = deleteAtIndex(head, 1);
    // printf("After deletion at Index \n");
    // traversalLinkedList(head);

    // head = deleteLastNode(head);
    // printf("After deletion at Last Node \n");
    // traversalLinkedList(head);

    // head = deleteAtValue(head, 48);
    // printf("After deletion at Value \n");
    // traversalLinkedList(head);

};
