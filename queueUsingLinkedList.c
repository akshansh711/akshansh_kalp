#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

typedef struct Queue {
    node *front;
    node *rear;
}queue;

int isEmpty(queue *qu) {
    if (qu->front == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *qu, int *size) {

    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter value you want to enqueue : ");
    int value;
    scanf("%d",&value);

    newNode->data = value;
    newNode->next = NULL;

    if (qu->front == NULL && qu->rear == NULL)
    {
        qu->front = newNode;
        qu->rear = newNode;
    }else{
        qu->rear->next = newNode;
        qu->rear = newNode;
    }
    (*size)++;
}

void dequeue(queue *qu,int *size) {

    if(isEmpty(qu)) {
        printf("queue is empty\n");
        return;
    }else if(qu->rear == qu->front){
        node *temp = qu->front;
        printf("Element popped from stack is %d\n",temp->data);

        qu->rear = NULL;
        qu->front = NULL;
        (*size)--;
    }else{
        node *temp = qu->front;
        printf("Element popped from stack is %d\n",temp->data);
        
        qu->front = qu->front->next;

        free(temp);
        (*size)--;
    }
}

void peek(queue *qu) {
    if (isEmpty(qu))
    {
        printf("queue is empty\n");
    }else{
        printf("Element at front is %d\n",qu->front->data);
    } 
}

void getSize(int *size) {
    if (*size == 0)
    {
        printf("queue is empty\n");
        return;
    }else{
        printf("size of queue is %d\n",*size);
    }
    
}

int main() {
    queue *qu = (queue *)malloc(sizeof(queue));
    qu->front = NULL;
    qu->rear = NULL;

    int size = 0;

    while (1)
    {
        printf("Enter 1 to perform enqueue operation\n");
        printf("Enter 2 to perform dequeue operation\n");
        printf("Enter 3 to know the front element of the queue\n");
        printf("Enter 4 to get the size of queue\n");
        printf("Enter 5 to exit\n\n");

        printf("Enter the operation you want to perform\n");
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                enqueue(qu,&size);
                break;
            
            case 2:
                dequeue(qu,&size);
                break;

            case 3:
                peek(qu);
                break;

            case 4:
                getSize(&size);
                break;

            case 5:
                printf("Terminating !!!\n");
                exit(1);
                break;

            default:
                printf("Invalid input !!!\n");
                break;
        }
    }
}
