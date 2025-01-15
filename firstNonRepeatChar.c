#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char ch;
    scanf("%c",&ch);
    getchar();
    
    char *str = (char *)malloc(100*sizeof(char));
    scanf("%[^\n]",str);
    
    int freq[27] = {0};
    
    int i=0;
    while(str[i] != '\0') {
        if(str[i] == ' ') {
            i++;
            continue;
        }else {
            freq[str[i] - 'a']++;
            i++;
        }
    }
    i=0;
    int ansInd = 0;
    while(str[i] != '\0') {
        if(freq[str[i]-'a'] == 1) {
            ansInd = i;
            str[ansInd] = ch;
            break;
        }
        i++;
    }
    
    
    
    printf("%s",str);
}
