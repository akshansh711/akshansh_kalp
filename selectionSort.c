#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int size) {
    for (int i = 0; i < size-1; i++)
    {
        int minInd = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
            
        }
        swap(&arr[i], &arr[minInd]);
    }
}

int main() {
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);

    int *array = (int *)malloc(size*sizeof(int));

    printf("Enter elements in array :- \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    
    selectionSort(array,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
}
