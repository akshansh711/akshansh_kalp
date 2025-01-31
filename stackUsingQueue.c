#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *array;
}queue;

int isFull(queue *qu,int size) {
    if(qu->rear == size-1) {
        return 1;
    }else{
        return 0;
    }
}

int pop(queue *qu, int *cnt) {

    int val = 0;

    if (qu->front == -1)
    {
        printf("Underflow !!!\n");
    }else if(qu->rear == qu->front) {
        printf("value deleted is %d\n",qu->array[qu->front]);
        qu->rear = -1;
        qu->front = -1;
    }else{
        val = qu->array[qu->front];
        printf("value is deleted is %d\n",qu->array[qu->front]);
        qu->front++;
        (*cnt)--;
    }
    return val;
}

void push(queue *qu,int size,int *cnt,int value) {
    
    if (isFull(qu,size))
    {
        printf("Overflow !!!\n");
        return;
    }
    
    if (qu->rear == -1)
    {
        qu->array[++qu->front] = value;
        qu->array[++qu->rear] = value;

        (*cnt)++;
    }
    else{
        qu->array[++qu->rear] = value;
        (*cnt)++;

        for(int i=0;i<*cnt-1;i++) {
            int temp = qu->array[qu->front];
            qu->front++;
            qu->rear++;
            qu->array[qu->rear] = temp;
        }
    }
}

void peek(queue *qu) {

    if (qu->front == -1)
    {
        printf("queue is empty\n");
    }else{
        printf("Element at front position is %d\n",qu->array[qu->front]);
    }
}

void getSize(int *cnt) {
    printf("Current size of stack is %d\n",*cnt);
}

int main() {

    queue *qu = (queue *)malloc(sizeof(queue));
    
    printf("Enter the size of stack : ");
    scanf("%d",&qu->size);
    int n = qu->size;
    qu->front = -1;
    qu->rear = -1;

    int cnt = 0;

    qu->array = (int *)malloc(n * sizeof(int));

    while (1)
    {
        
        printf("Enter 1 to push an element in stack\n");
        printf("Enter 2 to pop an element from stack\n");
        printf("Enter 3 to know the top element of the stack\n");
        printf("Enter 4 to get the size of stack\n");
        printf("Enter 5 to exit\n\n");

        printf("Enter the operation you want to perform\n");
        int choice,value;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                value = 0;
                printf("Enter the value you want to insert : ");
                scanf("%d",&value);
                push(qu,n,&cnt,value);
                break;
            
            case 2:
                pop(qu,&cnt);
                break;

            case 3:
                peek(qu);
                break;

            case 4:
                getSize(&cnt);
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
