#include<stdio.h>
#include<stdlib.h>

int main() {
    int freq[26] = {0};

    char str[100];
    scanf("%s",str);

    int i=0;
    char fnr = '0';
    int flag = 0;
    while(str[i] != '\0') {
        if (freq[str[i] - 'a'] == 0)
        {
            if(fnr == '0') {
                printf("%c",str[i]);
                fnr = str[i];
            }else{
                printf("%c",fnr);
            }
            freq[str[i] - 'a']++;
        }else if(freq[str[i] - 'a'] > 0) {
            printf("-1");
            fnr = '0';
        }
        i++;
    }
}
