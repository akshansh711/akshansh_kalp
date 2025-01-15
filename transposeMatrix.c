#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int size;
    scanf("%d",&size);
    int **arr = (int **)malloc(size * sizeof(int *));
    
    for(int i=0;i<size;i++) {
        arr[i] = (int *)malloc(size * sizeof(int *));
        for(int j=0;j<size;j++) {
             scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(i == j || j < i) {
                continue;
            }else {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
