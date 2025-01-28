#include<stdio.h>
#include<stdlib.h>

void setMatZero(int **mat, int rowSize, int colSize) {
    int firstRowZero = 0, firstColZero = 0;

    for (int j = 0; j < colSize; j++) {
        if (mat[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for (int i = 0; i < rowSize; i++) {
        if (mat[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for (int i = 1; i < rowSize; i++) {
        for (int j = 1; j < colSize; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0; 
                mat[0][j] = 0; 
            }
        }
    }

    for (int i = 1; i < rowSize; i++) {
        if (mat[i][0] == 0) {
            for (int j = 0; j < colSize; j++) {
                mat[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < colSize; j++) {
        if (mat[0][j] == 0) {
            for (int i = 0; i < rowSize; i++) {
                mat[i][j] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < colSize; j++) {
            mat[0][j] = 0;
        }
    }

    if (firstColZero) {
        for (int i = 0; i < rowSize; i++) {
            mat[i][0] = 0;
        }
    }
}

int main() {
    int rowSize;
    scanf("%d",&rowSize);

    int colSize;
    scanf("%d",&colSize);

    int **mat = (int **)malloc(rowSize*sizeof(int *));

    for (int i = 0; i < rowSize; i++)
    {
        mat[i] = (int *)malloc(colSize*sizeof(int));
    }
    
    for(int i=0; i < rowSize; i++){
        for(int j=0; j<colSize; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    setMatZero(mat,rowSize,colSize);

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
