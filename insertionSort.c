#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    
}

int main() {
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);

    int *arr = (int *)malloc(size*sizeof(int));

    printf("Enter elements in array :- \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    insertionSort(arr,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
}
