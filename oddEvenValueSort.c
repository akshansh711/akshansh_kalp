#include<stdio.h>
#include<stdlib.h>
 

typedef struct Node {
    int data;
    struct Node *next;
}node;

typedef struct List
{
    node *head;
    node *tail;
}list;

void createLL(node **head, node **tail) {
    int val;
    printf("Enter the value you want to add in the linked list : ");
    scanf("%d",&val);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void createCustom(node **head, node **tail, int val) {

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//ascending
void sortEven(node **head) {
    node *temp1 = *head;
    node *temp2 = *head;

    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if(temp1->data > temp2->data) {
                swap(&temp1->data, &temp2->data);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

//descending
void sortOdd(node **head) {
    node *temp1 = *head;
    node *temp2 = *head;

    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if(temp1->data < temp2->data) {
                swap(&temp1->data, &temp2->data);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void oddEven(node **head, node **oddHead, node **oddTail, node **evenHead, node **evenTail) {
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    
    node *temp = *head;
    while (temp != NULL)
    {
        int val = temp->data;

        if (val % 2 == 0)
        {
            createCustom(&*evenHead,&*evenTail,val);
        }else{
            createCustom(&*oddHead, &*oddTail, val);
        }
        temp = temp->next;
    }
    
    sortEven(&*evenHead);
    sortOdd(&*oddHead);


    if (*evenHead == NULL)
    {
        *evenHead = *oddHead;
    }
    else if (*evenTail != NULL)
    {
        (*evenTail)->next = *oddHead;    
    }
    
    
}

void printLL(node **head) {
    if(*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }else{
        node *temp = *head;
        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    list *l1 = (list *)malloc(sizeof(list));
    l1->head = NULL;
    l1->tail = NULL;

    list *oddList = (list *)malloc(sizeof(list));
    oddList->head = NULL;
    oddList->tail = NULL;

    list *evenList = (list *)malloc(sizeof(list));
    evenList->head = NULL;
    evenList->tail = NULL;

    int size;
    printf("Enter the size of linked list : ");
    scanf("%d",&size);

    for (int i = 0; i < size; i++)
    {
        createLL(&l1->head, &l1->tail);
    }
    
    oddEven(&l1->head,&oddList->head,&oddList->tail,&evenList->head,&evenList->tail);

    printLL(&evenList->head);
}
