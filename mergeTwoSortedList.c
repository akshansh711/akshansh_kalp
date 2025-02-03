#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

typedef struct List
{
    node *head;
    node *tail;
}list;

void createLL(node **head, node **tail) {
    printf("Enter the value you want to add in linked list : ");
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

    while (first != NULL && second!= NULL)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }else{
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
    }
    
    while (first != NULL)
    {
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }

    while (second != NULL)
    {
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }
    
    return dummy->next;
}

node* mergesort(node *head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node *mid = findMid(head);

    head = mergesort(head);
    mid = mergesort(mid);

    return merge(head,mid);
}

node* mergeTwoSorted(node *head1, node *head2) {
    node *dummy = (node *)malloc(sizeof(node));
    dummy->data = -1;
    dummy->next = NULL;

    node *temp = dummy;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 -> data < head2 -> data)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }else{
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
           
    }

    while (head1 != NULL)
    {
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }
    
    while (head2 != NULL)
    {
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }
    
    return dummy->next;
}

void printLL(node **head) {
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }else{
        node *temp = *head;

        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

int main() {
    list *l1 = (list *)malloc(sizeof(list));
    l1->head = NULL;
    l1->tail = NULL;

    list *l2 = (list *)malloc(sizeof(list));
    l2->head = NULL;
    l2->tail = NULL;

    int n1;
    printf("Enter size of list 1 : ");
    scanf("%d",&n1);

    for (int i = 0; i < n1; i++)
    {
        createLL(&l1->head,&l1->tail);
    }

    int n2;
    printf("Enter size of list 2 : ");
    scanf("%d",&n2);

    for (int i = 0; i < n2; i++)
    {
        createLL(&l2->head,&l2->tail);
    }

    node *newl1Head = mergesort(l1->head);
    node *newl2Head = mergesort(l2->head);

    printLL(&newl1Head);
    printLL(&newl2Head);

    node *mergeHead = mergeTwoSorted(newl1Head, newl2Head);

    printLL(&mergeHead);
}
