#include<stdio.h>
#define max 7

int search(int arr[max],int n,int l, int size){
    int low =l;
    int high = size-1;
    if(low>high)
        return -1 ;
    int mid = (low+high)/2 ;
    if(arr[mid]==n){
        return mid ;
    }
    if(n<arr[mid])
        return search(arr,n,l,mid);
    if(n>arr[mid])
        return search(arr,n,mid+1,high);
}
int main(){
    int array[max] = {12,34,42,45,67,82,90};
    int n;
    int size ;
    printf("enter the number to be searched :");
    scanf("%d",&n);
    size = sizeof(array) /sizeof(array[0]);
    //printf("%d",size);
    int index = search(array,n,0,size);
    if(index==-1){
        printf("element not found");
    }
    else{
        printf("fount at index: %d",index);
    }
    return 0 ;
}