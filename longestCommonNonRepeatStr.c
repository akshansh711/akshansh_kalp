#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("Enter no. of strings : ");
    int n;
    scanf("%d",&n);

    int freq[n][26];

    memset(freq,0,n*26*sizeof(int));

    char str[n][100];

    for (int i = 0; i < n; i++)
    {
        scanf("%s",str[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int j=0;
        while(str[i][j] != '\0') {
            freq[i][str[i][j] - 'a']++;
            j++;
        }   
    }


    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         printf("%d ",freq[i][j]);
    //     }
    //     printf("\n");
    // }
    
    
    int maxLen = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++) {
            int k=0;
            int common = 0;
            while(str[i][k] != '\0') {
                if (freq[i][str[i][k] - 'a'] > 0 && freq[j][str[i][k] - 'a'] > 0)
                {
                    common = 1;
                    break;
                }
                k++;
            }

            if(!common) {
                int len1 = strlen(str[i]);
                int len2 = strlen(str[j]);
                int temp = len1 * len2;

                if (maxLen < temp)
                {
                    maxLen = temp;
                }
                
            }
        }
    }
    printf("%d",maxLen);
}
