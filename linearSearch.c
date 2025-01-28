#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *arr, int num, int size) {

    for (int i = 0; i < size; i++)
    {
        if(arr[i] == num) {
            return i+1;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);

    int *array = (int *)malloc(size*sizeof(int));
    
    printf("Enter elements in array :-\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    
    int num;
    printf("Enter the element you want to search for : ");
    scanf("%d",&num);

    int pos = linearSearch(array,num,size);

    if (pos == -1)
    {
        printf("Element no found !!!");
    }else{
        printf("Element found at position : %d",pos);
    }
    
}
