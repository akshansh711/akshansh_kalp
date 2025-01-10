#include<stdio.h>
#include<string.h>

int findLength(char str[]) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char to[], char from[]) {
    int i=0;
    
    while(from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

int validInput(int min, int max) {
    char string[101];
    scanf("%s",string);

    int value = 0;
    int index = 0;
    int isValid = 0;

    while(string[index] != '\0') {
        if(string[index] >= '0' && string[index] <= '9') {
            isValid = 1;
        }else {
            isValid = 0;
            break;
        }
        index++;
    }

    if(isValid) {
        value = 0;
        index = 0;
        for(index = 0; string[index] != '\0'; index++) {
            value = value * 10 + (string[index] - '0');
        }
        if(value > max || value < min) {
            isValid = 0;
        }
    }

    if(!isValid) {
        printf("Invalid input !!!");
            return -1;
    }else {
            return value;
    }
}

int main() {
    int rows,columns;
    printf("Enter number of rows ");
    rows = validInput(1,10);

    
    if(rows == -1) {
        return 0;
    }
    printf("Enter number of columns ");
    columns = validInput(1,101);
    
    if(columns == -1) {
        return 0;
    }

    char students[rows][columns][51];

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
