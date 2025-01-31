#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    int *array;
}stack;

int isEmpty(int top) {
    if (top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void push(stack *st) {

    if(st->top == st->size-1) {
        printf("Stack overflow !!!\n");
        return;
    }else{
        printf("Enter the value you want to insert : ");
        int value;
        scanf("%d",&value);

        st->top++;
        st->array[st->top] = value;
    }
}

void pop(stack *st) {

    if(isEmpty(st->top)) {
        printf("Underflow, insert an element in the stack !!!\n");
        return;
    }else{
        printf("Element popped is %d\n",st->array[st->top]);
        st->top--;
    }
}

void peek(stack *st) {

    if (isEmpty(st->top))
    {
        printf("Stack is empty\n");
    }else{
        printf("Element at top is %d\n",st->array[st->top]);
    }
}

void getSize(int top) {

    if (isEmpty(top))
    {
        printf("Currently there are no elements in the stack\n");
    }else{
        printf("The current size of stack is %d\n",top+1);
    }
}

int main() {

    stack *st = (stack *)malloc(sizeof(stack));
    
    printf("Enter the size of stack : ");
    scanf("%d",&st->size);
    int n = st->size;
    st->top = -1;

    st->array = (int *)malloc(n * sizeof(int));

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
                push(st);
                break;
            
            case 2:
                pop(st);
                break;

            case 3:
                peek(st);
                break;

            case 4:
                getSize(st->top);
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
