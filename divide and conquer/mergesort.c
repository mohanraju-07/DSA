#include<stdio.h>
#define max 4

int array[max] ={23,35,42,25} ;

void merge(int array[max],int low ,int mid, int high){
    int temp[high-low+1] ;
    int i= low ;
    int j =mid+1 ;
    int k =0 ;

    while (i <= mid && j <= high) {
        if (array[i] < array[j]) 
            temp[k++] = array[i++];
        else 
            temp[k++] = array[j++];
    }
    while(i<=mid){
        temp[k] = array[i];
        i++;
        k++ ;
    }
    while(j<=high){
        temp[k] =array[j];
        j++;
        k++;
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        array[i] = temp[k];
    }

}
void mergesort(int low, int high){
    if(low<high){
        int mid = (low+high)/2 ;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(array,low,mid,high);
    }
}

int main(){
    mergesort(0,max-1);
    for(int i=0;i<max;i++){
        printf("%d ",array[i]);
    }
    return 0 ;

}