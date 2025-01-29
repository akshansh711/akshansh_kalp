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

int getId(node **newNode, node **head) {

    printf("Enter id of patient : ");
    scanf("%d",&(*newNode)->id);
    int flag = 0;
    

    node *temp = *head;
    while (temp != NULL)
        {
            if(temp->id == (*newNode)->id) {
                printf("ID already exists\n");
                return 1;
            }
            temp = temp->next;
        }

        return 0;
}

int getSeverity(node **newNode, node **head) {

    printf("Enter severity of patient : ");
    scanf("%s",&(*newNode)->severity);
    int flag = 0;

    node *temp = *head;
        if(strcmp((*newNode)->severity, "critical") != 0 && strcmp((*newNode)->severity, "stable") != 0
           && strcmp((*newNode)->severity, "serious") != 0
        ){
            printf("Invalid input !!!\n");
            return 1;
        }
}


void createLL(node **head, node **tail) {

    node *newNode = (node *)malloc(sizeof(node));

    if(getId(&newNode,&*head)) {
        getId(&newNode,&*head);
    }

    if (getSeverity(&newNode,&*head))
    {
        getSeverity(&newNode,&*head);
    }
    

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
    node *dummy2 = (node *)malloc(sizeof(node));
    node *dummy3 = (node *)malloc(sizeof(node));

    dummy1->next = dummy2->next = dummy3->next = NULL;

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
    temp1->next = NULL;
    temp2->next = NULL;
    temp3->next = NULL;

    node *newHeadTemp = NULL;
    if (dummy1->next)
    {
        newHeadTemp = dummy1->next;
        if (dummy2->next)
        {
            temp1->next = dummy2->next;
        }else{
            temp1->next = dummy3->next;
        }
    }else if(dummy2->next) {
        newHeadTemp = dummy2->next;
        temp2->next = dummy3->next;
    }else{
        newHeadTemp = dummy3->next;
    }
    
    return newHeadTemp;

    // temp1->next = dummy2->next;
    // temp2->next = dummy3->next;
    
    // return dummy1->next;
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
        printf("\n");
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

    printLL(&newHead);
}

