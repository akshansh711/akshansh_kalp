#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void createLL(node **head, node **tail) {
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter value to add in linked list : ");
    int val;
    scanf("%d",&val);
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

node* partition(node *head, node *tail, node **newHead, node **newTail) {
    node *pivot = tail;
    node *prev = NULL;
    node *curr = head, *end = tail;

    while (curr != pivot)
    {
        if(curr->data < pivot->data) {
            if (*newHead == NULL)
            {
                *newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }else{
            if (prev)
            {
                prev->next = curr->next;
            }
            node *temp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = curr;
            curr = temp;
        }
    }

    if (*newHead == NULL)
    {
        *newHead = pivot;
    }
    
    *newTail = end;
    return pivot;
}

node* quicksort(node *head, node *tail) {
    if (head == NULL || head == tail)
    {
        return head;
    }
    node *newHead = NULL, *newTail = NULL;
    node *pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot)
    {
        node *temp = newHead;

        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;

        newHead = quicksort(newHead,temp);

        node *last = newHead;
        while (last->next)
        {
            last = last->next;
        }
        last->next = pivot;
    }
     
    pivot->next = quicksort(pivot->next, newTail);
    return newHead;
}

void findKthSmallestEle(node *head) {
    int k;
    printf("Enter k value for kth smallest element : ");
    scanf("%d",&k);

    k -=1;
    node *temp = head;
    while (k > 0)
    {
        temp = temp->next;
        k--;
    }
    printf("%d",temp->data);
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
    node *head = NULL;
    node *tail = NULL;

    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        createLL(&head, &tail);
    }
    head = quicksort(head,tail);

    printLL(&head);

    findKthSmallestEle(head);
}
