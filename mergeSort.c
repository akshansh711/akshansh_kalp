#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int start,int mid, int end) {

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1],R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[start+i]; 
    }
    
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    
    int i=0,j=0,k=start;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int start, int end) {

    if(start >= end) {
        return ;
    }

    int mid = start + (end-start)/2;
    mergeSort(array,start,mid);
    mergeSort(array,mid+1,end);
    merge(array,start,mid,end);

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
    
    mergeSort(array,0,size-1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    
    
}
