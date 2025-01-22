// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}node;

typedef struct List {
    node *head;
    node *tail;
}list;


int n = 0;

void insertNode(node **head, node **tail) {
    printf("Enter value : ");
    int val;
    scanf("%d",&val);
    
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> data = val;
    newNode -> next =  NULL;
    newNode -> prev = NULL;
    
    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }else{
        (*tail)->next = newNode;
        newNode -> prev = *tail;
        *tail = newNode;
    }
}

int display(node **head) {
    if(*head == NULL)  {
        return 0;
    }else{
        node *temp = *head;
        while(temp != NULL) {
            
        }
    }
}


int sumNode(node **head, node **tail,int k) {
    if(head == NULL) {
        return 0;
    }
    int sum = 0;
    node *temp = *tail;
    while(k!=0) {
        if(temp == NULL) {
            break;
        }
        sum += temp->data;
        temp = temp->prev;
        k--;
    }
    
    return sum;
}

void printAll(int sumArr[], int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",sumArr[i]);
    }
}

int main() {
    // Write C code here
    list *l1 = (list  *)malloc(sizeof(list));
    l1->head = NULL;
    l1->tail = NULL;
    
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    
    int sumArr[n];
    int sum = 0;
    int itr = 0;
    
    getchar();
    
    char choice;
    for(int i=0;i<n;i++) {
        scanf("%c",&choice);
        switch(choice) {
            case 'a' :
                insertNode(&l1->head, &l1->tail);
                getchar();
                break;
            case 's' :
                sum = sumNode(&l1->head, &l1->tail,k);
                sumArr[itr] = sum;
                itr++;
                getchar();
                break;
            case 'p' :
                printAll(sumArr,itr);
                getchar();
                break;
            default :
                printf("Invalid");
                return 0;
        }
    }

    return 0;
}
