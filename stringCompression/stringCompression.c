#include<stdio.h>
#include<stdlib.h>

int main() {
    char *input_string = (char *)malloc(100*sizeof(char));    
    scanf("%s",input_string);

    char *res = (char *)malloc(50*sizeof(char));

    int i=0,cnt = 1,itr = 0;
    while (input_string[i] != '\0')
    {
        if(input_string[i] == input_string[i+1]) {
            cnt++;
        }else if(input_string[i] != input_string[i+1]) {
            res[itr] = input_string[i];
            int temp = cnt;

            itr++;
        if(cnt != 1) {
            int rem[10], itrRem = 0;
            while (temp != 0)
            {
                rem[itrRem] = temp % 10;
                itrRem++;
                temp = temp/10;
            }
            for (int j = itrRem-1; j >= 0 ; j--)
            {
                res[itr] = rem[j] + '0';
                itr++;
            }
        }
            cnt = 1;
        }
        i++;
    }
    res[itr] = '\0';
    printf("%s",res);
}