#include<stdio.h>
#include<stdlib.h>

void subsetSum(int arr[], int res[], int n, int ind, int j, int sum, int target) {

    if (sum == -1)
    {
        sum = 0;
    }
    else if (sum == target)
    {
        for (int i = 0; i < j; i++)
        {
            printf("%d ",res[i]);
        }
        printf("\n");
        return;
    }
    if (sum > target)
    {
        return;
    }
    
    if (ind == n)
    {
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (i != ind && arr[i] == arr[i-1]) continue;
        
        res[j] = arr[i];
        subsetSum(arr,res,n,i+1,j+1,sum+arr[i],target);
    }
}

void sort(int arr[],int n) {
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Printf enter the size of array : ");
    scanf("%d",&size);

    int *arr = (int *)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr,size);

    int target;
    printf("Enter the target value : ");
    scanf("%d",&target);

    int *res = (int *)malloc(size*sizeof(int));
    int sum = -1;

    subsetSum(arr,res,size,0,0,sum,target);
}
