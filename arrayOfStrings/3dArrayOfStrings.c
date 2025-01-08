#include<stdio.h>
#include<string.h>

int findLength(char str[]) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    return len;
}

void stringCopy(char to[], char from[]) {
    int i=0;
    
    while(from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

int validInput(int min) {
    int value;
    while(scanf("%d",&value) != 1 || value < min) {
        printf("Invalid input !!!");
        return -1;
    }
    return value;
}

int main() {
    int rows,columns;
    printf("Enter number of rows ");
    rows = validInput(0);
    
    if(rows == -1) {
        return 0;
    }
    printf("Enter number of columns ");
    columns = validInput(0);
    
    if(columns == -1) {
        return 0;
    }

    char students[rows][columns][50];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("students at (%d,%d): ",i,j);
            scanf("%s",students[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%s ",students[i][j]);
        }
        printf("\n");
    }
    
    int cnt = 0;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(
               students[i][j][0] == 'a' || students[i][j][0] == 'e' ||
               students[i][j][0] == 'i' || students[i][j][0] == 'o' ||
               students[i][j][0] == 'u' || students[i][j][0] == 'A' ||
               students[i][j][0] == 'E' || students[i][j][0] == 'I' || 
               students[i][j][0] == 'O' || students[i][j][0] == 'U' 
            ){
                cnt++;
            }
        }
    }
    
    printf("Number of elements starting with a vowel: %d\n",cnt);
    
    int maxLength = 0;
    char longestName[50];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int len = findLength(students[i][j]);
            if(len > maxLength) {
                maxLength = len;
                stringCopy(longestName, students[i][j]);
            }
        }
        
    }
    
    printf("The longest name is %s",longestName);
}
