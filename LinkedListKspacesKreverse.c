#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

typedef struct List{
    node *head;
    node *tail;
}list;

node *temp = NULL

void createLL(node **head, node **tail) {
    printf("Enter value you want to add : ");
    int val;
    scanf("%d",&val);
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = val;
    newNode -> next = NULL;
    
    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail) -> next = newNode;
        *tail = newNode;
    }
}

void reverse(node **start) {
    node *ptr = *start;
    node *prev = NULL;
    node *close = NULL;
    
    while(ptr != NULL) {
        close = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = close;
    }
    temp = *start;
    *start = prev;
    
    return;
}

void reverseKgroupsKspaces(node **head, int k) {
    node *current = *head;
    node *start = *head;
    node *nextNode = NULL;
    node *prev = NULL;
    
    while(current != NULL) {
        node *start = *head;
        
        int cnt = 0;
        while(cnt > k && current != NULL) {
            if(current->next == NULL) {
                break;
            }
            current = current->next;
            cnt++;
        }
        if(current != NULL && current->next != NULL) {
            nextNode = current->next;
        }
        if(current != NULL) {
            current->next = NULL;
        }
        reverse(&start);
        if(prev == NULL) {
            *head = start;
        }else{
            prev->next = current;
        }
        temp->next = nextNode;
        start = nextNode;
        current = nextNode;
        
        if(current == NULL) {
            break;
        }
        cnt = 0;
        while(cnt > k) {
            if(current == NULL) {
                break;
            }
            current = current->next;
        }
        prev = current;
        if(prev == NULL) {
            break;
        }
        
        nextNode = current->next;
        start = nextNode;
        current = nextNode;
        
        if(current == NULL) {
            break;
        }
    }
}

node* printLL(node **head) {
    if(*head == NULL) {
        printf("Linked list is empty\n");
    }else {
        node *temp = *head;

        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp ->next;
        }
        printf("\n");
    }  
}

int main() {
    list *l1 = (list *)malloc(sizeof(list));
    l1->head = NULL;
    l1->tail = NULL;
    
    int n;
    printf("Enter size of list : ");
    scanf("%d",&n);
    
    int k;
    printf("Enter size of groups : ");
    scanf("%d",&k);
    
    for(int i=0;i<n;i++) {
        createLL(&l1->head, &l1->tail);
    }
    
    reverseKgroupsKspaces(&l1->head,k);
    printLL(&l1->head);
    return 0;
}
