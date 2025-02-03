#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void createLL(node **head, node **tail) {
    printf("Enter the value you want to add : ");
    int val;
    scanf("%d",&val);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void createCircular(node **head, node **tail) {
    (*tail)->next = *head;
}

node* findMid(node *head) {
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *fake = slow->next;
    slow->next = NULL;
    return fake;
}

node* merge(node *first, node *second) {
    node *dummy = (node *)malloc(sizeof(node));
    dummy->data = -1;
    dummy->next = NULL;

    node *temp = dummy;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            temp=temp->next;
            first=first->next;
        }else{
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
        
    }
    

    while (first != NULL) {
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }

    while (second != NULL) {
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }
    
    return dummy->next;
}

node* mergesort(node *head) {
    if (!head || head->next ==  NULL)
    {
        return head;
    }
    
    node *mid = findMid(head);

    head = mergesort(head);
    mid = mergesort(mid);

    return merge(head,mid);
}


void printLL(node **head) {
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }else{
        node *temp = *head;

        do 
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }while((temp!=*head));
        printf("\n");
    }
    
}

void searchValue(node *head) {
    int val;
    printf("Enter the value you want to search for : ");
    scanf("%d",&val);

    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
           printf("%d\n",cnt);
           return;
        }
        cnt++;
        temp = temp->next;
    }
    printf("-1");
}

int main() {
    node *head = NULL;
    node *tail = NULL;

    int n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        createLL(&head,&tail);
    }

    createCircular(&head,&tail);
    (tail)->next = NULL;
    
    node *newHead = mergesort(head);
    node *temp = newHead;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newHead;

    searchValue(newHead);

    printLL(&newHead);
}
