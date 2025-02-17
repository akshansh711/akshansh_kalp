#include<stdio.h>
#include<stdlib.h>

int main() {
    int frequency[26] = {0};

    char input[100];
    scanf("%s",input);

    int i=0;
    char fnr = '0';
    

    while (input[i] != '\0')
    {
        frequency[input[i] - 'a']++;

        int fnd = 0;
        for (int j = 0; j <= i ; j++)
        {
            if (frequency[input[j] - 'a'] == 1)
            {
                printf("%c",input[j]);
                fnd = 1;
                break;
            }
        }
        if (!fnd)
        {
            printf("-1");
        }
        i++;
        
    }
    

}
