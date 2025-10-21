#include<stdio.h>
#include<stdlib.h>

struct dll {
    struct dll* prev;
    int data;
    struct dll* next ;
};

struct dll* create(int data){
    struct dll* newnode = (struct dll*)malloc(sizeof(struct dll));
    newnode->data = data;
    newnode->prev=NULL;
    newnode->next =NULL ;
    return newnode ;
};
struct dll* insertion(int data,int pos,struct dll* head){
    struct dll* temp =head ;
    struct dll* newnode =create(data);

    if(pos==0){
        newnode->next=temp;
        temp->prev= newnode ;
        return newnode;
    }
    if(pos == -1){
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next=newnode;
        newnode->prev = temp ;
        return head ;
    }
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    if (temp == NULL) return head; 

    newnode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
    return head ;
}

struct dll* delete(int data,struct dll* head){
    if(head==NULL){
        printf("linked list is empty");
        return head;
    }
    if(head->data ==data){
        head=head->next;
        if(head !=NULL){
            head->prev=NULL;
        }
        return head ;
        
    }

    struct dll* temp =head ;
    while(temp!=NULL && temp->data!=data){
        temp=temp->next ;
    }
    if(temp==NULL){
        printf("no data found");
        return head;
    }
    if(temp->next==NULL){
        temp->prev->next=NULL ;
        free(temp);
        return head ;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev ;
    free(temp);
    return head ;
}

void traverse(int way,struct dll* head){
    struct dll* temp = head ;
    if (way == 1) {
        // Forward traversal
        printf("Forward traversal:\n");
        while (temp != NULL) {
            printf("%d", temp->data);
            if (temp->next != NULL)
                printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }
    if(way==-1){
        printf("backward traversal\n");
        while(temp->next!=NULL){
            temp= temp->next;
        }
        while(temp!=NULL){
            printf("%d",temp->data);
            if(temp->prev!=NULL){
                printf("->");
            }
            temp= temp->prev ;
        }
        printf("\n");
    }
    
}

int main(){
    struct dll* head = create(10);
    struct dll* n2 =create(20);

    head->next= n2 ;
    n2->prev = head;

    struct dll* temp=head;

    head = insertion(12,0,head);
    head =insertion(35,1,head);
    head = insertion(24,-1,head);

    temp =head;
    while(temp!=NULL){
        printf("value %d\n",temp->data);
        temp=temp->next;
    }
    printf("deletion\n");
    head=delete(20,head);
    temp=head ;
    while(temp!=NULL){
        printf("value %d\n",temp->data);
        temp=temp->next;
    }
    
    traverse(-1,head);
    traverse(1,head);
    return 0;

};