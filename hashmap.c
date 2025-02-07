#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TableSize 10

typedef struct Node {
    int key;
    int value;
    struct Node *next;
}node;

int hash(int key) {
    return key % TableSize;
}

void insert(node **arr) {
    int key;
    printf("Enter key : ");
    scanf("%d",&key);

    int hashVal = hash(key);

    int value;
    printf("Enter value : ");
    scanf("%d",&value);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;

    newNode->next = NULL;

    if (arr[hashVal] == NULL)
    {
        arr[hashVal] = newNode;
    }else{
        node *temp = arr[hashVal];

        while (temp->next && temp->key != key)
        {
            temp = temp->next;
            if (temp->key == key)
            {
                temp->value = value;
            }
            
        }
        temp->next = newNode;
    }
}

void search(node **arr) {
    int key;
    printf("Enter key : ");
    scanf("%d",&key);

    int hashVal = hash(key);

    if (arr[hashVal] == NULL)
    {
        return;
    }else{
        node *temp = arr[hashVal];
        while (temp && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        printf("%d\n",temp->value);
    }
}

void delete(node **arr) {
    int key;
    printf("Enter key : ");
    scanf("%d",&key);

    int hashVal = hash(key);

    if (arr[hashVal] == NULL)
    {
        return;
    }else{
        node *temp = arr[hashVal];
        if (temp->key == key)
        {
            arr[hashVal] = temp->next;
            free(temp);
            printf("Key deleted %d\n",key);
            return;
        }
        node *prev = NULL;
        while (temp->next && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->key == key)
        {
            prev->next = temp->next;
            free(temp);
            printf("Key deleted %d\n",key);
        }else{
            printf("Not Found\n");
        }   
    }
}

void display(node **arr) {
    printf("\nHashmap\n");

    bool isEmpty = true;
    for(int i=0; i < TableSize;i++) {
        if (arr[i])
        {
            isEmpty = false;
            node *temp = arr[i];

            printf("Index %d : ",i);
            bool first = true;
            while (temp)
            {
                printf(first ? "(%d, %d)" : "->(%d, %d)",temp->key, temp->value);
                first = false;
                temp = temp->next;
            }
            printf("\n");
        }
    }
    if (isEmpty)
    {
        printf("Empty\n");
    }
    
}

int main() {
    node **arr = (node **)calloc(TableSize,sizeof(node*));
    int index = 0;

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                insert(arr);
                break;
            case 2:
                search(arr);
                break;
            case 3:
                delete(arr);
                break;
            case 4:
                display(arr);
                break;
            case 5:
                printf("Terminatiing\n");
                exit(1);
            default:
                break;
        }
    }
    
}
