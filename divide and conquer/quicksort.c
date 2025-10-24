#include<stdio.h>
#define max 7 

int arr[max]= {12,32,65,127,34,25,38};

void swap (int *a ,int *b){
    int temp = *a ;
    *a=*b;
    *b=temp;
}

int partion(int arr[max],int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end =ub;
    while (start<end){
        while (start <= ub && arr[start] <= pivot)
            start++;
        while (end >= lb && arr[end] > pivot)
            end--;
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end ;

}

void quicksort(int arr[max],int lb,int ub){
    if(lb<ub){
        int loc = partion(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int main(){
    quicksort(arr,0,max-1);
    for(int i=0;i<max;i++){
        printf("%d ",arr[i]);
    }
    return 0 ;
}