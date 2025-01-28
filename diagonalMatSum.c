#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Enter size of matrix : ");
    scanf("%d",&n);

    int **arr = (int **)malloc(n*sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n*sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i][i];
        sum += arr[n-i-1][i];
    }
    
    if (n%2 != 0)
    {
        sum -= arr[n/2][n/2];
    }
    printf("%d",sum);
}
