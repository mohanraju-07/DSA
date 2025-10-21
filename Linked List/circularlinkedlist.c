#include<stdio.h>
#include<stdlib.h>

struct ll{
    int data;
    struct ll* next;
};

struct ll* create(int data){
    struct ll* newnode = (struct ll*)malloc(sizeof(struct ll));
    newnode->data =data ;
    return newnode;
}
struct ll* insert(int data, int pos, struct ll* first){
    struct ll* temp = first;
    struct ll* newnode =create(data);
    if(pos==0){
        while(temp->next!= first){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->next=first;
        first= newnode;
        return first;
    }
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next = newnode ;
    return first;

}
struct ll* delete(int data,struct ll* first){
    struct ll*prev =NULL ;
    printf("\ndeletion\n");
    struct ll* temp=first;
    if(first->data==data){
        while(temp->next!=first){
            temp=temp->next ;
        }
        temp->next = first->next;
        first= first->next;
        return first;
    }
    while(temp->data!=data ){
        prev=temp ;
        temp=temp->next;
    }
    if(temp->next!=first){
        prev->next =temp->next ;
        return first ;
    }
    prev->next = temp->next;
    return first;



}
int main(){
    struct ll* first = create(10);
    struct ll* n2= create(20);
    struct ll* last =create(30);
    first->next=n2;
    n2->next=last;
    last->next = first ;
    struct ll* temp =first;
    first= insert(01,0,first);
    first= insert(25,3,first);
    temp=first;
    do {
        printf("%d ",temp->data);
        temp= temp->next;
    }while(temp!=first) ;
    first=delete(1,first);
    first = delete(25,first);
    first = delete(30,first);
    temp=first;
    do {
        printf("%d ",temp->data);
        temp= temp->next;
    }while(temp!=first) ;

    return 0 ;
}