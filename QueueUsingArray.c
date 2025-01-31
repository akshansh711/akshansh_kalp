#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int rear;
    int front;
    int size;
    int *array;
}queue;

int isEmpty(queue *qu) {
    
    if (qu->front == -1)
    {
        return 1;
    }else{
        return 0;
    }
    
}

void enqueue(queue *qu) {
    printf("Enter the value to enqueue : ");
    int value;
    scanf("%d",&value);

    if (qu->rear == qu->size-1)
    {
        printf("Overflow !!!\n");
        return;
    }else if(qu->front == -1 && qu->rear == -1){
        qu->front++;
        qu->rear++;

        qu->array[qu->front] = value;
        qu->array[qu->rear] = value;
    }else{
        qu->rear++;
        qu->array[qu->rear] = value;
    }
}

void dequeue(queue *qu) {

    if (isEmpty(qu))
    {
        printf("Underflow, there is no element to delete\n");
    }else if (qu->rear == qu->front)
    {
        printf("Element dequeued is %d\n",qu->array[qu->front]);
        qu->front = -1;
        qu->rear = -1;
    }
    else{
        printf("Element dequeued is %d\n",qu->array[qu->front]);
        qu->front++;
    }
    
}

void peek(queue *qu) {

    if (isEmpty(qu))
    {
        printf("queue is empty\n");
    }else{
        printf("Element at front is %d\n",qu->array[qu->front]);
    }
}

void getSize(queue *qu) {

    if (isEmpty(qu))
    {
        printf("Currently there are no elements in the stack\n");
    }else{
        printf("The current size of queue is %d\n",(qu->rear - qu->front)+1);
    }
}

int main() {

    queue *qu = (queue *)malloc(sizeof(queue));
    
    printf("Enter the size of queue : ");
    scanf("%d",&qu->size);
    int n = qu->size;

    qu->rear = -1;
    qu->front = -1;

    qu->array = (int *)malloc(n * sizeof(int));

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
                enqueue(qu);
                break;
            
            case 2:
                dequeue(qu);
                break;

            case 3:
                peek(qu);
                break;

            case 4:
                getSize(qu);
                break;

            case 5:
                printf("Terminating !!!\n");
                break;

            default:
                printf("Invalid input !!!\n");
                break;
        }
    }
    
}
