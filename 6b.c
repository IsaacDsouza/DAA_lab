//Merge Sort
#include<stdio.h>
#include<stdlib.h> 

// Merges two subarrays of arr[]. 
// First subarray is arr[beg..mid] 
// Second subarray is arr[mid..end] 

void merge(int arr[], int beg, int mid, int end){
    
    int i, j, k;

    int n1 = mid - beg +1;
    int n2 = end-mid;

    int leftarray[n1], rightarray[n2];

    for(int y=0; y<n1; y++)
        leftarray[y]=arr[beg+y];
    
    for(int x=0; x<n2; x++)
        rightarray[x]=arr[mid+1+x];
    
    i=0;
    j=0;
    k=beg;

    while(i<n1 && j<n2){
        if(leftarray[i]<=rightarray[j]){
            arr[k]=leftarray[i];
            i++;

        }
        else{
            arr[k]=rightarray[j];
            j++;

        }
        k++;
    }
    while(i<n1){
        arr[k]=leftarray[i];
        i++;
        k++;

    }
    while(j<n2){
        arr[k]= rightarray[j];
        j++;
        k++;
    }


}

void mergesort(int arr[], int beg, int end){
    if(beg<end){
        int mid = (beg+end)/2;
        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);
        merge(arr, beg, mid, end);
    }
}
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  

int main()  
{  
    int a[] = { 12, 31, 25, 8, 32, 17, 40, 42 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArray(a, n);  
    mergesort(a, 0, n - 1);  
    printf("After sorting array elements are - \n");  
    printArray(a, n);  
    return 0;  
}  
