#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

typedef struct List {
    node *head;
    node *tail;
}list;

int takeInput(int value) {
    scanf("%d",&value);
    if(value < -1000 || value > 1000) {
        printf("Out of bounds !!!");
        exit(0);
    }
    return value;
}

int addAtEnd(node **head, node **tail, int *sizeLL) {
    printf("Enter the value you want to add at the end : ");
    int val;
    val = takeInput(val);
    
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    (*sizeLL)++;
    printf("size of linked list %d\n",*sizeLL);
}   

void addAtBeg(node **head, node **tail,int *sizeLL) {
    printf("Enter the value you want to add at the beginning : ");
    int val;
    val = takeInput(val);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
    }else{
        newNode->next = *head;
        *head = newNode;
    }
    (*sizeLL)++;
}

int insertRandom(node **head, node **tail, int *sizeLL) {
    int ind,val;
    printf("Enter the index where you want to insert : ");
    scanf("%d",&ind);

    if(ind < 0) {
        printf("Out of Bounds !!!");
        return 0;
    }

    if (ind > *sizeLL+1)
    {
        printf("Out of bound !!!\n");
        return 0;
    }else if(ind == 1) {
        addAtBeg(head,tail,sizeLL);
    }else if(ind == *sizeLL) {
        addAtEnd(head,tail,sizeLL);
    }else{
    
    printf("Enter the data you want insert : ");
    val = takeInput(val);


    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    node *temp = *head;
    node *prev = *head;

    for (int i = 0; i < ind-1; i++)
    {
        prev = temp;
        temp = temp->next;
    }

        prev -> next = newNode;
        newNode -> next = temp;
    }
        (*sizeLL)++;
}

int updateLL(node **head, node **tail,int *sizeLL) {
    int ind, val;
    printf("Enter the index you want to update : ");
    scanf("%d",&ind);

    if(ind < 0) {
        printf("Out of bounds !!!");
        return 0;
    }

    if(ind > *sizeLL) {
        printf("Out of bounds !!!\n");
        return 0;
    }

    printf("Enter the value you want to add : ");
    val = takeInput(val);
    
    if (*head == NULL)
    {
        printf("Linked list is empty !!!\n");
        return 0;
    }else{
        if(ind == 1) {
            (*head)-> data = val;
        }else {
            node *temp = *head;
            for (int i = 0; i < ind-1; i++)
            {
                temp = temp->next;
            }
            temp->data = val;
        }
    } 
}   

int deleteFirst(node **head, node **tail, int *sizeLL) {
    if (*head == NULL)
    {
        printf("Linked list is empty \n");
        return 0;
    }else{
        node *temp = *head;
        *head = (*head)->next;

        free(temp);
    }
    (*sizeLL)--;
}

int deleteLast(node **head, node **tail, int *sizeLL) {
    if(*head == NULL) {
        printf("Linked list is empty \n");
        return 0;
    }else if((*head)->next == NULL) {
        *head = (*head)->next;
    }else{  
        node *temp = *head;
        node *prev = *head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev->next = NULL;
        *tail = prev;
        free(temp);
    }
    (*sizeLL)--;
}

int deleteRandom(node **head, node **tail, int *sizeLL) {
    int ind;
    printf("Enter the index of node you want to delete : ");
    scanf("%d",&ind);

    if(ind < 0) {
        printf("Out of bounds !!!");
        return 0;
    }

    if(ind > *sizeLL) {
        printf("Out of bound !!!\n");
        return 0;
    }
    
    if(*head == NULL) {
        printf("Linked list is empty \n");
        return 0;
    }
    if (ind == 1)
    {
        deleteFirst(head,tail,sizeLL);
        return 0;
    }else if(ind == *sizeLL) {
        deleteLast(head,tail,sizeLL);
    }else{
        node *prev = *head;
        node *temp = *head;
        for (int i = 0; i < ind-1; i++)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = temp->next;
        free(temp);
    }
    (*sizeLL)--;
}

node* display(node **head) {
    if(*head == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }else {
        node *temp = *head;
        while (temp!=NULL)
        {
            printf("%d ",temp -> data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {

    list *l1 = (list *)malloc(sizeof(list));
    l1->head = NULL;
    l1->tail = NULL;

    int sizeLL = 0;

    int n, choice;
    printf("Enter the number of operations you want to perform : ");
    scanf("%d",&n);

    if(n < 1 || n > 100) {
        printf("Out of bounds !!!\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                addAtEnd(&l1->head, &l1->tail, &sizeLL);
                break;
            case 2:
                addAtBeg(&l1->head, &l1->tail, &sizeLL);
                break;
            case 3:
                insertRandom(&l1->head, &l1->tail, &sizeLL);
                break;
            case 4:
                display(&l1->head);
                break;
            case 5:
                updateLL(&l1->head, &l1->tail,&sizeLL);
                break;
            case 6:
                deleteFirst(&l1->head, &l1->tail,&sizeLL);
                break;
            case 7:
                deleteLast(&l1->head, &l1->tail,&sizeLL);
                break;
            case 8:
                deleteRandom(&l1->head, &l1->tail, &sizeLL);
                break;
            default:
                printf("Invaild choice\n");
                return 0;
        }
    }
    
}
