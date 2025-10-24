#include<stdio.h>
#define max 6
int queue[max];

int front =-1 ;
int rear = -1 ;

void insert(int data){
    if(rear==max-1){
        printf("queue is full");
    }else {
        if(front==-1){
            front=0;
        }
        
        queue[++rear] = data;
        printf("%d is added! \n ",data);
    }

}
void display(){
    if(front==-1 || front >rear){
        printf("queue empty");
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
int main(){
    insert(10);
    insert(3);
    display();


    return 0 ;

}