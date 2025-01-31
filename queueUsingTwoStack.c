#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int *array;
} stack;

typedef struct queue {
    stack *s1;
    stack *s2;
} queue;

int isEmpty(stack *st) {
    return st->top == -1;
}

void push(stack *st, int value, int size) {
    if (st->top == size - 1) {
        printf("Stack Overflow !!!\n");
        return;
    }
    st->array[++st->top] = value;
}

int pop(stack *st) {
    if (isEmpty(st)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->array[st->top--];
}

void enqueue(queue *q1, int size) {
    printf("Enter the value you want to insert: ");
    int value;
    scanf("%d", &value);
    push(q1->s1, value, size);
}

int dequeue(queue *q, int size) {
    if (isEmpty(q->s2)) {  
        while (!isEmpty(q->s1)) {
            int temp = pop(q->s1);
            push(q->s2, temp, size);
        }
    }
    if (isEmpty(q->s2)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(q->s2);
}

int queueSize(queue *q) {
    return (q->s1->top + 1) + (q->s2->top + 1);
}

int peek(queue *q, int size) {
    if (isEmpty(q->s2)) {
        while (!isEmpty(q->s1)) {
            int temp = pop(q->s1);
            push(q->s2, temp, size);
        }
    }
    if (isEmpty(q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->s2->array[q->s2->top];
}

void display(queue *q) {
    if (isEmpty(q->s1) && isEmpty(q->s2)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->s2->top; i >= 0; i--) {
        printf("%d ", q->s2->array[i]);
    }
    for (int i = 0; i <= q->s1->top; i++) {
        printf("%d ", q->s1->array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    queue *q = (queue *)malloc(sizeof(queue));
    q->s1 = (stack *)malloc(sizeof(stack));
    q->s2 = (stack *)malloc(sizeof(stack));

    q->s1->top = -1;
    q->s2->top = -1;

    q->s1->array = (int *)malloc(size * sizeof(int));
    q->s2->array = (int *)malloc(size * sizeof(int));

    while (1) {
        printf("Enter 1 to perform enqueue operation\n");
        printf("Enter 2 to perform dequeue operation\n");
        printf("Enter 3 to know the front element of the queue\n");
        printf("Enter 4 to get the size of queue\n");
        printf("Enter 5 to exit\n\n");

        printf("Enter the operation you want to perform\n");
        int choice;
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                enqueue(q, size);
                break;
            case 2: {
                int dequeued = dequeue(q, size);
                if (dequeued != -1) {
                    printf("Dequeued: %d\n", dequeued);
                }
                break;
            }
            case 3: {
                int front = peek(q, size);
                if (front != -1) {
                    printf("Front: %d\n", front);
                }
                break;
            }
            case 4:
                printf("Queue Size: %d\n", queueSize(q));
                break;
            case 5:
                display(q);
                break;
            case 6:
                printf("Exiting...\n");
                free(q->s1->array);
                free(q->s2->array);
                free(q->s1);
                free(q->s2);
                free(q);
                return 0;
            default:
                printf("Invalid input!\n");
                break;
        }
    }
}
