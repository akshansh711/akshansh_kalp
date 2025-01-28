#include<stdio.h>
#include<stdlib.h>

int twoPointerSearch(int *arr,int num, int n) {
    int start = 0;
    int end = n-1;

    while (start <= end)
    {
        if (arr[start] == num)
        {
            return start+1;
        }
        if (arr[end] == num)
        {
            return end+1;
        }
        start++;
        end--;
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

    int pos = twoPointerSearch(array,num,size);

    if (pos == -1)
    {
        printf("Element no found !!!");
    }else{
        printf("Element found at position : %d",pos);
    }
    
}
