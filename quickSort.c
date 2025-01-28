#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low,int high) {
    int pivot = arr[high];

    int i = low-1;

    for (int j = low; j <= high-1; j++)
    {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int part = partition(arr,low,high);

        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);

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
    
    quickSort(array,0,size-1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
}
