#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size;
    int *array;
} queue;

int isEmpty(queue *q) {
    if (q->front == -1)
    {
        return 1;
    }else{
        return 0;
    }
}

int isFull(queue *q) {
    if (q->rear == q->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}

void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->array[++q->rear] = value;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = q->array[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else q->front++;
    return val;
}

void push(queue **q1, queue **q2, int value) {
    enqueue(*q2, value);
    while (!isEmpty(*q1)) {
        enqueue(*q2, dequeue(*q1));
    }
    queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

int pop(queue *q1) {
    if (isEmpty(q1)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue(q1);
}

int peek(queue *q1) {
    if (isEmpty(q1)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return q1->array[q1->front];
}

int main() {
    int n;
    printf("Enter size of stack: ");
    scanf("%d", &n);

    queue *q1 = (queue *)malloc(sizeof(queue));
    q1->rear = q1->front = -1;
    q1->array = (int *)malloc(n * sizeof(int));

    queue *q2 = (queue *)malloc(sizeof(queue));
    q2->rear = q2->front = -1;
    q2->array = (int *)malloc(n * sizeof(int));

    while (1) {
        printf("\nEnter 1 to push an element in stack\n");
        printf("Enter 2 to pop an element from stack\n");
        printf("Enter 3 to know the top element of the stack\n");
        printf("Enter 4 to exit\n");

        printf("Enter your choice: ");
        int choice, value;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(&q1, &q2, value);
                break;
            case 2:
                printf("Popped element: %d\n", pop(q1));
                break;
            case 3:
                printf("Top element: %d\n", peek(q1));
                break;
            case 4:
                printf("Terminating!\n");
                free(q1->array);
                free(q2->array);
                free(q1);
                free(q2);
                return 0;
            default:
                printf("Invalid input!\n");
        }
    }
}
