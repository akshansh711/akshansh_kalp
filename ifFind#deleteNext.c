#include <stdio.h>
#include <string.h>

void deleteEle(char *input, char *output)
{
    int i = 0, j = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '#')
        {
            if (j > 0)
            {
                j--;
            }
        }
        else
        {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
}
int main()
{
    char str1[200], str2[200];
    
    printf("Enter string 1 : ");
    scanf("%s", str1);
    printf("Enter string 2 : ");
    scanf("%s", str2);

    char newStr1[200], newStr2[200];

    deleteEle(str1, newStr1);
    deleteEle(str2, newStr2);

    printf("string 1: %s\n", newStr1);
    printf("string 2: %s\n", newStr2);

    if (strcmp(newStr1, newStr2) == 0)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
