#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "user.txt"

typedef struct
{
    char firstName[20];
    char lastName[20];
    int id;
    int age;
} Users;

void userDetails(char *firstName, char *lastName, int *age) {
    getchar();

    printf("Enter Firstname: ");
    fgets(firstName, 20, stdin);
    firstName[strcspn(firstName, "\n")] = '\0';

    printf("Enter Lastname: ");
    fgets(lastName, 20, stdin);
    lastName[strcspn(lastName, "\n")] = '\0';

    printf("Enter user age: ");
    scanf("%d",age);
}

void newUser()
{
    Users user;

    FILE *fptr = fopen(FILENAME, "a");
    if (!fptr)
    {
        printf("file does not exist");
        return;
    }
    printf("Enter unique userId ");
    scanf("%d", &user.id);

    userDetails(user.firstName, user.lastName, &user.age);

    fprintf(fptr, "%d %s %s %d\n", user.id, user.firstName, user.lastName, user.age);
    fclose(fptr);
    printf("User added successfully\n");
}

void updateUser()
{
    Users user;
    int id, fnd = 0;

    printf("Enter id of user you want to update : ");
    scanf("%d", &id);

    FILE *fptr = fopen(FILENAME, "r");
    if (!fptr)
    {
        printf("File not found\n");
        return;
    }

    FILE *fptr1 = fopen("temp.txt", "w");
    if (!fptr1)
    {
        printf("Error creating temp.txt file\n");
        return;
    }

    while (fscanf(fptr, "%d %s %s %d", &user.id, user.firstName, user.lastName, &user.age) != EOF)
    {
        if (user.id == id)
        {
            fnd = 1;
            userDetails(user.firstName, user.lastName, &user.age);
        }
        fprintf(fptr1, "%d %s %s %d\n", user.id, user.firstName, user.lastName, user.age);
    }
    fclose(fptr);
    fclose(fptr1);

    if (fnd)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User updated successfully");
    }
    else
    {
        remove("temp.txt");
        printf("User not found");
    }
}

void displayUser()
{
    FILE *fptr = fopen(FILENAME, "r");
    Users user;

    if (!fptr)
    {
        printf("File doesn't exist\n");
        return;
    }

    printf("\nUser Records:\n");
    printf("ID\tName\t\tAge\n");

    while (fscanf(fptr, "%d %s %s %d", &user.id, user.firstName, user.lastName, &user.age) != EOF)
    {
        printf("%d\t%s %s\t%d\n", user.id, user.firstName, user.lastName, user.age);
    }

    fclose(fptr);
}

void deleteUser()
{
    Users user;
    int id, fnd = 0;

    printf("Enter id of user you want to delete : ");
    scanf("%d", &id);

    FILE *fptr = fopen(FILENAME, "r");

    if (!fptr)
    {
        printf("Error opening file\n");
        return;
    }

    FILE *fptr1 = fopen("temp.txt", "w");
    if (!fptr1)
    {
        printf("Error creating file\n");
        return;
    }
    while (fscanf(fptr, "%d %s %s %d", &user.id, user.firstName, user.lastName, &user.age) != EOF)
    {
        if (user.id == id)
        {
            fnd = 1;
            continue;
        }
        else
        {
            fprintf(fptr1, "%d %s %s %d\n", user.id, user.firstName, user.lastName, user.age);
        }
    }
    fclose(fptr);
    fclose(fptr1);

    if (fnd)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User successfully deleted \n");
    }
    else
    {
        remove("temp.txt");
        printf("User not found \n");
    }
}

int main()
{
    int options;
    do
    {
        printf("Select the operation you want to perform \n");
        printf("1. Create a new record or file \n");
        printf("2. Update an existing record \n");
        printf("3. Display all existing record \n");
        printf("4. Delete an existing record \n");
        printf("5. Enter 5 for exit \n");
        printf("Enter the operation you want to perform ");
        scanf("%d", &options);

        switch (options)
        {
        case 1:
            newUser();
            break;
        case 2:
            updateUser();
            break;
        case 3:
            displayUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Termination...");
            break;
        default:
            printf("Invalid choice");
        }
    } while (options != 5);
}