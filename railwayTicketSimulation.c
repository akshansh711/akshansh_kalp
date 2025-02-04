#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {
    GENERAL,
    SENIOR_CITIZEN,
    VIP
}type;

typedef struct Passenger {
    int id;
    char name[20];
    type levels;
}passenger;

typedef struct Queue{
    int rear;
    int front;
    int size;
    passenger *p;
}queue;

type getType(char category[]){

    if(strcmp(category,"GENERAL")==0){
        return GENERAL;
    }else if(strcmp(category, "SENIOR_CITIZEN") == 0) {
        return SENIOR_CITIZEN;
    }else if(strcmp(category, "VIP") == 0) {
        return VIP;
    }
}

void enqueue(queue *q1, int *itr) {
    // int id;
    // char category[20];
    // char name[10];
    // 3 scanf();
    // q[front].t=t;
    // type t=getType(category);

    int id;
    char name[100]; 

    printf("Enter id of passenger : ");
    scanf("%d",&id);

    printf("Enter name of passenger : ");
    scanf("%s",name);

    char category[20];

    printf("Enter type of passenger : ");
    scanf("%s",category);

    type t = getType(category);

    if (q1->front == -1)
    {
        ++(q1->rear);
        q1->p[q1->rear].id = id;

        strcpy(q1->p[q1->rear].name, name);
        q1->p[q1->rear].levels = t;
        ++(q1->front);
        (*itr)++;
    }else{
        int index = ++q1->rear;
        while (index-1 >= q1->front && q1->p[index-1].levels < t)
        {
            q1->p[index] = q1->p[index-1];
            index--;
        }
        q1->p[index].id = id;
        strcpy(q1->p[index].name, name);
        q1->p[index].levels = t; 
    }
}

char* getStringType(int t) {
    if (t == 0)
    {
        return "GENERAL";
    }else if(t == 1) {
        return "SENIOR_CITIZEN";
    }else{
        return "VIP";
    }
    
}

void dequeue(queue *q1) {
    if (q1->front == -1 || q1->front > q1->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    char typelvl[20];
    strcpy(typelvl, getStringType(q1->p[q1->front].levels));
    printf("Serving passenger is %d, %s, type : %s\n",q1->p[q1->front].id, q1->p[q1->front].name,typelvl);
    
    q1->front++;
}

void displayQueue(queue *q1) {
    if (q1->front == -1)
    {
        printf("Queue is empty\n");
    }
    
    for (int i = q1->front; i <= q1->rear; i++)
    {
        printf("%d %s %d\n",q1->p[i].id,q1->p[i].name,q1->p[i].levels);
    }
}

int main() {
    int n;
    printf("Enter number of operations : ");
    scanf("%d",&n);

    queue *q1 = (queue *)malloc(sizeof(queue));
    q1->front = q1->rear = -1;

    q1->p = (passenger *)malloc(n*sizeof(passenger));
    int itr = 0;

    for (int i = 0; i < n; i++)
    {
        int choice;
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue(q1,&itr);
            break;
        
        case 2:
            dequeue(q1);
            break;

        case 3:
            displayQueue(q1);
            break;

        default:
            break;
        }
    }
    
}
