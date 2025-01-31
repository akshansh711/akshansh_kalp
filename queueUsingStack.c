#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int top;
    int *array;
}stack; 

int isFull(stack *st, int size) {
    if(st->top == size-1) {
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(stack *st) {
    return st->top == -1;
}

void push(stack *st, int value,int size) {
    if (isFull(st,size))
    {
        printf("Stack Overflow\n");
        return;
    }
    st->array[++st->top] = value;
}

void enqueue(stack *st,int size) {
    printf("Enter the value you want to inser : ");
    int value;
    scanf("%d",&value);

    push(st,value,size);
}

int pop(stack *st) {
    return st->array[st->top--];
}

int dequeue(stack *st,int size) {
    if (isEmpty(st))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int val = pop(st);
    if (isEmpty(st))
    {
        return val;
    }
    
    int temp = dequeue(st,size);
    push(st,val,size);
    return temp;
}

int peek(stack *st, int size) {
    if (isEmpty(st))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = pop(st);

    if (isEmpty(st))
    {
        push(st,value,size);
        return value;
    }
    int temp = peek(st,size);
    push(st,value,size);
}

void display(stack *st,int size) {
    if (isEmpty(st))
    {
        printf("Queue is Empty\n");
        return;
    }
    int value = pop(st);
    display(st,size);
    printf("%d",value);
    push(st,value,size);
}

int getSize(stack *st) {
    return st->top+1;
}

int main() {
    int size;
    printf("Enter size of queue : ");
    scanf("%d",&size);

    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;

    st->array = (int *)malloc(size*sizeof(int));

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
                enqueue(st,size);
                break;
            
            case 2: {
                int dequeued = dequeue(st,size);
                if (dequeued != -1)
                {
                    printf("Dequeued : %d\n",dequeued);
                }
                display(st,size);
                }
                break;
            case 3: {
                int front = peek(st,size);
                if (front != -1)
                    {
                    printf("Front : %d\n", front);
                    }
                }
                break;
            case 4:
                display(st,size);
                printf("Size of queue is %d\n",getSize(st));
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
