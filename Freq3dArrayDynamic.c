#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int freq;
}map;

void takeInput(char ***inpString, int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        inpString[i] = (char **)malloc(cols * sizeof(char*));
        for (int j = 0; j < cols; j++)
        {
            inpString[i][j] = (char *)malloc(50*sizeof(char));
            scanf("%s",inpString[i][j]);
        }   
    }
}

int calculateFreq(char ***inpString, int rows, int cols, map *mp) {
    
    int itr = 0, fnd = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fnd = 0;
            for (int k = 0; k < itr; k++)
            {
                if(strcmp(mp[k].word, inpString[i][j]) == 0) {
                    fnd = 1;
                    mp[k].freq++;
                    break;
                }
            }
            if(!fnd) {
                mp[itr].word = inpString[i][j];
                mp[itr].freq = 1;
                itr++;
            }
        }
        
    }
    return itr;
}

int main() {
    printf("Enter rows and columns : ");
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    char ***inpString = (char ***)malloc(rows*sizeof(char**));

    map *mp = (map *)malloc(rows*cols*sizeof(map));
    
    takeInput(inpString,rows,cols);

    int count = calculateFreq(inpString,rows,cols,mp);

    for (int i = 0; i < count; i++)
    {
        printf("%s : %d\n",mp[i].word, mp[i].freq);
    }
    

    return 0;
}
