#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setZero(int** mat, int r, int* c);

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    
    int** mat = (int **)malloc(sizeof(int *) * r);
    for(int i = 0; i < r; i++){
        mat[i] = (int *)malloc(sizeof(int) * c);
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    setZero(mat, r, &c);
    
    printf("[");
    for(int i = 0; i < r; i++){
        printf("[");
        for(int j = 0; j < c; j++){
            printf("%d", mat[i][j]);
            if(j != c - 1){
                printf(" ");
            }
        }
        printf("]");
        if(i != r - 1){
            printf(",");
        }
    }
    printf("]");
    
    return 0;
}

void setZero(int** mat, int r, int* c) {
    bool firstR = false, firstC = false;

    for(int i = 0; i < r; i++){
        if(mat[i][0] == 0){
            firstC = true;
            break;
        }
    }

    for(int j = 0; j < *c; j++){
        if(mat[0][j] == 0){
            firstR = true;
            break;
        }
    }

    for(int i = 1; i < r; i++){
        for(int j = 1; j < *c; j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < r; i++){
        for(int j = 1; j < *c; j++){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
    }

    if(firstR){
        for(int i = 0; i < *c; i++){
            mat[0][i] = 0;
        }
    }

    if(firstC){
        for(int i = 0; i < r; i++){
            mat[i][0] = 0;
        }
    }
}
