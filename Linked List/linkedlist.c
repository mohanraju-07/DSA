#include<stdio.h>
#include<stdlib.h>

struct linkedlist
{
    int data ;
    struct linkedlist* address ;
    
};
int length =0;
struct linkedlist* create(int data){
    struct linkedlist* node  = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    node->data =data;
    node->address =NULL;
    return node ;
}
struct linkedlist* search(int data,struct linkedlist* node){
    struct linkedlist* route =node;
    while(route!=NULL){
        if(route->data == data){
            return route;
        }else{
            route= route->address ;
        }
    }
    return 0;
}
struct linkedlist* insertion(int pos,int data,struct linkedlist* head){
    int index= 0;
    struct linkedlist* route =head ;
    struct linkedlist* newnode =create(data);
    if(pos == 0){
        newnode->address = head ;
        head = newnode ;
        length++ ;
        return head ;
        
    }
    while(index<pos-1 && route!=NULL){
        route=route->address ;
        index++;

    }
    newnode->address=route->address ;
    route->address= newnode;
    length++;
    
    return head ;

}

struct linkedlist* deletion(int data,struct linkedlist* head){
    if(head==NULL){
        printf("its empty");
        return head ;
    }
    struct linkedlist* temp =head ;
    struct linkedlist* prev =NULL ;
    if(temp->data==data){
        head = temp->address ;
        free(temp);
        length-- ;
        return head;
    }
    while(temp!=NULL && temp->data!=data){
        prev = temp ;
        temp = temp->address;
    }
    if (temp == NULL) {
        printf("Element not found!\n");
        return head;
    }

    prev->address = temp->address;
    free(temp);
    length--;
    return head;
}

struct linkedlist* getnthnode(int index,struct linkedlist* head){
    for(int i=0;i<index;i++){
        head=head->address ;
    }
    return head ;
}
int main(){
    struct linkedlist* head = create(4);
    struct linkedlist* n2 = create(3);
    struct linkedlist* n3 = create(10);
    struct linkedlist* n4 = create(34);
    head->address = n2 ;
    n2->address =n3 ;
    n3->address = n4;
    struct linkedlist* route =head;
    while(route!= NULL){
        printf("Value: %d\n", route->data);
        length++ ;
        route = route->address;

    }
    /*length of the linked list*/
    printf("the length of the linked list is %d\n",length);

    /*search an element */
    struct linkedlist* elemn = search(100,head);
    if(elemn!=NULL){
        printf("element found\n");
    }else{
        printf("element not found\n");
    }

    /*insertion at some position*/
    head = insertion(0,45,head) ;
    route =head ;
    while(route!= NULL){
        printf("Value: %d\n", route->data);
        route = route->address;

    }
    printf("the length of the linked list is %d\n",length);

    /*deletion*/
    head = deletion(50,head);
    route=head;
    while(route!=NULL){
        printf("value :%d\n",route->data);
        route=route->address ;
    }
    head = getnthnode(4,head);
    printf("the value at tht index is :%d\n",head->data);

    return 0 ;
}