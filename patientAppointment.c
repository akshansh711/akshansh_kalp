#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PATIENT
{
    int id;
    char severity[20];
}patient;


typedef struct Node{
    int id;
    char severity[20];
    struct Node *next;
}node;

typedef struct List
{
    node *head;
    node *tail;
}list;

void createLL(node **head, node **tail) {

    node *newNode = (node *)malloc(sizeof(node));

    printf("Enter id of patient : ");
    scanf("%d",&newNode->id);
    printf("Enter severity of patient : ");
    scanf("%s",newNode->severity);

    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

node* sortPatient(node *head, node **newHead, node **newTail) {
    if(head == NULL) {
        printf("Linked list is empty !!!\n");
        return NULL;
    }

    node *dummy1 = (node *)malloc(sizeof(node));
    dummy1->id = -1;
    dummy1->next = NULL;
    node *dummy2 = (node *)malloc(sizeof(node));
    dummy2->id = -1;
    dummy2->next = NULL;
    node *dummy3 = (node *)malloc(sizeof(node));
    dummy3->id = -1;
    dummy3->next = NULL;

    node *temp1 = dummy1;
    node *temp2 = dummy2;
    node *temp3 = dummy3;

    node *current = head;

    while (current != NULL)
    {
        
        if(strcmp(current->severity, "critical") == 0) {
            temp1->next = current;
            temp1 = temp1->next;
            
        }else if(strcmp(current->severity, "serious") == 0) {
            temp2->next = current;
            temp2 = temp2->next;
        }else{
            temp3->next = current;
            temp3=temp3->next;
        }

        current = current->next;
    }

    temp1->next = dummy2->next;
    temp2->next = dummy3->next;
    
    return dummy1->next;
}

void printLL(node **head) {
    if(*head == NULL) {
        printf("Linked list is empty\n");
    }else{
        node *temp = *head;

        while (temp != NULL)
        {
            printf("%d : %s\n",temp->id, temp->severity);
            temp = temp->next;
        }
        
    }
}

int main() {
    list *l1 = (list *)malloc(sizeof(list));
    l1->head = NULL;
    l1->tail = NULL;

    list *newList = (list *)malloc(sizeof(list));
    newList->head = NULL;
    newList->tail = NULL;

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        createLL(&l1->head, &l1->tail);
    }
    printLL(&l1->head);

    node *newHead = sortPatient(l1->head,&newList->head,&newList->tail);

    // printLL(&newHead);
}
