#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "users.txt"

typedef struct 
{
    char *name;
    int id;
    int age;
} Users;

char* get_Username() {

    char *name = (char*)malloc(sizeof(char)); 
    if (!name) {
        printf("Unable to allocate memory\n");
        return NULL;
    }

    printf("Enter username: ");
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n') 
    {
        name = (char*)realloc(name, i + 2); 
        if (!name) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        name[i] = ch;
        i++;
    }
    name[i] = '\0'; 

    return name;
}

int get_ID() {
    int id;
    printf("Enter unique userId : ");

    while (scanf("%d",&id) != 1)
    {
        while (getchar() != '\n');
        printf("Enter a valid ID : ");
    }
    return id;
}

void newUser() {
    Users user;
    int id,fnd = 0;

    FILE *fptr = fopen(FILENAME,"r");
    if(!fptr) {
        printf("File does not exist \n");
        return;
    }

    id = get_ID();
    if(!id) {
        fclose(fptr);
        return;
    }

    char tempName[100]; 
    while (fscanf(fptr,"%d %[^\t\n] %d",&user.id, tempName, &user.age) != EOF)
    {
        if(user.id == id) {
            fnd = 1;
            printf("This user id is already taken, Please try another one\n");
            break;
        }
    }
    if (fnd)
    {
        fclose(fptr);
        return;
    }
    fclose(fptr);

    fptr = fopen(FILENAME,"a");
    if(!fptr) {
        printf("File not found");
        return;
    }

    user.id = id;
    getchar();

    user.name = get_Username();
    if(!user.name) {
        fclose(fptr);
        return;
    }

    printf("Enter age : ");
    scanf("%d",&user.age);

    fprintf(fptr, "%d\t%s\t\t%d\n", user.id, user.name, user.age);
    free(user.name);
    fclose(fptr);
}

void updateUser() {
    Users user;
    int id = 0, fnd = 0;

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

    while (fscanf(fptr, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        
        if (user.id == id)
        {
            fnd = 1;
            getchar();

            user.name = (char*)malloc(sizeof(char));
            if(!user.name) {
                printf("Memory allocation failed\n");
                fclose(fptr);
                return;
            }

            printf("Enter username : ");
            char ch;
            int i = 0;
            while ((ch = getchar()) != '\n')
            {
                user.name = (char*)realloc(user.name,i+2);
                if(!user.name) {
                    printf("Memory allocation failed\n");
                    fclose(fptr);
                    return;
                }

                user.name[i] = ch;
                i++;
            }
            user.name[i] = '\0';

            printf("Enter age : ");
            scanf("%d",&user.age);
        }
        fprintf(fptr1, "%d\t%s\t\t%d\n", user.id, user.name, user.age);
    }
    fclose(fptr);
    fclose(fptr1);

    if (fnd)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User updated successfully\n");
    }
    else
    {
        remove("temp.txt");
        printf("User not found with id %d\n",id);
    }
}

void displayUser() {
    FILE *fptr = fopen(FILENAME, "r");
    Users user;

    if (!fptr)
    {
        printf("File doesn't exist\n");
        return;
    }

    printf("\nUser Records:\n");
    printf("ID\tName\t\tAge\n");

    while (1)
    {
        user.name = (char*)malloc(100);
        if(!user.name) {
            printf("Memory allocation failed.\n");
            fclose(fptr);
            return;
        }

        if (fscanf(fptr,"%d %[^\t\n] %d",&user.id,user.name,&user.age) == 3)
        {
            printf("%d\t%s\t%d\n",user.id,user.name,user.age);
        }else{
            free(user.name);
            break;
        }

        free(user.name);
    }
    
    fclose(fptr);
}

void deleteUser() {
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

    while (1)
    {
        user.name = (char*)malloc(100);
        if(!user.name) {
            printf("Memory not allocated\n");
            fclose(fptr);
            fclose(fptr1);
            return;
        }
        if (fscanf(fptr,"%d %[^\t\n] %d",&user.id, user.name, &user.age) != 3)
        {
            free(user.name);
            break;
        }
        
        if(user.id == id) {
            fnd = 1;
        }else {
            fprintf(fptr1, "%d\t%s\t\t%d\n",user.id,user.name,user.age);
        }

        free(user.name);
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
        printf("User not found with id %d\n",id);
    }
}

int main() {

    FILE *fptr = fopen(FILENAME,"r");
    if(!fptr) {
        fptr = fopen(FILENAME,"a");
        printf("File created successfully.\n");
    }
    fclose(fptr);

    int options = 0;
    do
    {
        printf("Select the operation you want to perform \n");
        printf("1. Create a new record or file \n");
        printf("2. Update an existing record \n");
        printf("3. Display all existing record \n");
        printf("4. Delete an existing record \n");
        printf("5. Enter 5 for exit \n");
        printf("Enter the operation you want to perform ");

        scanf("%d",&options);

        switch (options) {
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
                printf("Termination....!!!");
                break;   
            default :
                printf("Invalid choice ");     
        }

    } while (options != 5);
    
    scanf("%d",&options);
}