#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 6 

int visited[max]={0};
int queue[max];
int parent[max];
int front=-1;
int rear =-1 ;

struct linkedlist{ 
    int data ;
    struct linkedlist* next ;
};

struct graph{
    int vertices ;
    struct linkedlist* adjlst[max] ;
};

struct linkedlist * create(int data){
    struct linkedlist* node = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    node->data =data ;
    node->next =NULL ;
    return node ;

}

struct graph * creategraph(int vertices){
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->vertices =vertices ;
    for(int i=0;i<vertices;i++){
        g->adjlst[i] =NULL ;
    }
    return g ;
}

void addedge(struct graph* graph ,int u,int v){
    struct linkedlist* newnode =create(v);
    newnode->next =graph->adjlst[u];
    graph->adjlst[u] =newnode ;

    newnode =create(u);
    newnode->next = graph->adjlst[v];
    graph->adjlst[v] =newnode; 
}
void printGraph(struct graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        struct linkedlist* temp = g->adjlst[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void enqueue(int data){
    if(front==-1){
        front =0;
    }
    queue[++rear] =data ;
    
}
int dequeue(){
    int d ;
    if(front<=rear){
        d= queue[front];
        front++ ;
    }
    return d ;
}

bool cycle(struct graph *g,int startnode){
    for(int i =0;i<g->vertices;i++){
        parent[i] =-1 ;
    }
    visited[startnode]= 1 ;
    enqueue(startnode);
    while(front<=rear){
        int u = dequeue();
        struct linkedlist* temp = g->adjlst[u];

        while(temp){
            int v = temp->data ;
            if(!visited[v]){
                visited[v]=1;
                parent[v] =u;
                enqueue(v);
            }
            else if(parent[u] !=v){ 
                return true ;

            }
            temp=temp->next;

        }
    }
    return false ;

    
}

int main(){
    struct graph* g =creategraph(6);

    addedge(g,0,1);
    //addedge(g,0,5);
    addedge(g,1,2);
    addedge(g,5,4);
    addedge(g,2,3);
    addedge(g,4,3);

    if(cycle(g,0)){
        printf("cycle exists\n");
    }else{
        printf("doesnt exists\n");
    }
    printGraph(g);

}