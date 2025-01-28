#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void sort(int *arr,int n) {
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int binarySearch(int *arr, int num, int size) {
    int low = 0;
    int high = size-1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high-low)/2;

        if(arr[mid] == num) {
            return mid+1;
        }else if(num >= arr[mid]) {
            low = mid+1;
        }else{
            high = mid-1;
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

    sort(array,size);
  
    int num;
    printf("Enter the element you want to search for : ");
    scanf("%d",&num);

    int pos = binarySearch(array,num,size);

    if (pos == -1)
    {
        printf("Element no found !!!");
    }else{
        printf("Element found at position : %d",pos);
    }
    
}
