#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

typedef struct Stack {
    node *top;
}stack;

int isEmpty(stack *st) {
    if (st->top == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack *st, int *size) {

    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter the value to insert in stack : ");
    int value;
    scanf("%d",&value);

    newNode->data = value;
    newNode->next = NULL;

    newNode->next = st->top;

    st->top = newNode;
    (*size)++;
}

void pop(stack *st,int *size) {
    if(isEmpty(st)) {
        printf("Stack is empty\n");
        return;
    }else{
        node *temp = st->top;
        printf("Element popped from stack is %d\n",temp->data);
        
        st->top = st->top->next;

        free(temp);
        (*size)--;
    }
}

void peek(stack *st) {
    if (isEmpty(st))
    {
        printf("Stack is empty\n");
    }else{
        printf("Element at top is %d\n",st->top->data);
    } 
}

void getSize(int *size) {
    if (*size == 0)
    {
        printf("stack is empty\n");
        return;
    }else{
        printf("size of stack is %d\n",*size);
    }
    
}

int main() {
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = NULL;

    int size = 0;

    while (1)
    {
        printf("Enter 1 to push an element in stack\n");
        printf("Enter 2 to pop an element from stack\n");
        printf("Enter 3 to know the top element of the stack\n");
        printf("Enter 4 to get the size of stack\n");
        printf("Enter 5 to exit\n\n");

        printf("Enter the operation you want to perform\n");
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                push(st,&size);
                break;
            
            case 2:
                pop(st,&size);
                break;

            case 3:
                peek(st);
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
