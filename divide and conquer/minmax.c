#include<stdio.h>
#include<stdlib.h>
#define size 6
struct pair {
    int min;
    int max;
};

int array[size] ={4,6,8,1,3,9};

struct pair * minmax(int low,int high){
    struct pair * node = (struct pair*)malloc(sizeof(struct pair));
    if(low==high){
        node->min=array[low];
        node->max =array[high];
        return node ;
    }
    if(high==low+1){
        if(array[low]<array[high]){
            node->min=array[low];
            node->max=array[high];
        }
        else{
            node->min =array[high];
            node->max =array[low];
        }
        return node ;

    }
    int mid = (low+high)/2 ;
    struct pair *left =minmax(low,mid);
    struct pair * right = minmax(mid+1,high);

    node->min = (left->min<right->min)? left->min:right->min;
    node->max = (left->max>right->max)? left->max:right->max;

    return node ;
}
int main(){
    struct pair * result = minmax(0,5);
    printf("minimum : %d \n",result->min);
    printf("maximum : %d\n",result->max);

    return 0;
}