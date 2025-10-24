#include <stdio.h>
#define max 4

int arr[max] ={8,4,2,1};
int count =0 ;

void merge(int arr[max],int low,int mid,int high){
    int temp[high-low+1];
    int i=low;
    int j=mid+1;
    int k =0 ;

    while(i<=mid&& j<=high){
        if(arr[i]<arr[j])
            temp[k++] =arr[i++];
        else
            temp[k++] =arr[j++] ;
            count+=(mid-i+1);
            printf("\n%d ",count);
    }
    while(i<=mid){
        temp[k] =arr[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergesort(int low, int high){
    if(low<high){
        int count =0;   
        int mid =(low+high)/2 ;
        mergesort(low,mid);
        mergesort(mid+1,high);
        /*while(low<high){
            if(arr[low]>arr[high])
                count++;
            low++;
        }*/
        merge(arr,low,mid,high);
    }
}
int main(){
    mergesort(0,max-1);
    for(int i=0;i<max;i++){
        printf("%d ",arr[i]);
    }
    printf("\ncount :%d",count);
    return 0 ;

}