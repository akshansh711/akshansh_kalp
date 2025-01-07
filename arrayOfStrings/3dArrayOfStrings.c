#include<stdio.h>
#include<string.h>

int main() {
    int rows,columns;
    printf("Enter number of rows ");
    scanf("%d",&rows);
    printf("Enter number of columns ");
    scanf("%d",&columns);

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
        for(int j = 0; j < columns; i++)
        {
            if(
              students[i][j][0] == 'a' ||students[i][j][0] == 'e' ||
               students[i][j][0] == 'i' ||students[i][j][0] == 'o' ||
               students[i][j][0] == 'u' ||students[i][j][0] == 'A' ||
               students[i][j][0] == 'E' ||students[i][j][0] == 'I' || 
               students[i][j][0] == 'O' ||students[i][j][0] == 'U' 
            ){
                cnt++;
            }
        }
    }
    
    int maxLength = 0;
    char longestName[50];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; i++)
        {
            int len = strlen(students[i][j]);
            if(len > maxLength) {
                maxLength = len;
                strcpy(longestName, students[i][j]);
            }
        }
        
    }
    
    printf("The longest name is ",longestName);
}