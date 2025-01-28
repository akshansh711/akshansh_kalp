#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *array, int size) {

    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(array[j] > array[j+1]) {
                swap(&array[j],&array[j+1]);
            }
        }
        
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
    
    bubbleSort(array,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
}
