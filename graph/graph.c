#include<stdio.h>

#define v 4 
#define max 5
int queue[max] ;
int front= -1;
int rear = -1;

int visited[max] ={0};

int output[v]
;
void addEdge(int mat[v][v],int i,int j){
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void display(int mat[v][v]){
    for(int i=0;i<v;i++){
        for(int j =0 ;j<v;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
void enqueue(int data){
    if(rear >=max-1){
        printf("queue full");
    }else{
        if(front==-1)
            front=0;
        rear++ ;
        queue[rear] =data ;
    }
}
int dequeue(){
    if(front==-1||front >rear){
        printf("queue empty");
    }
    else{
        int val = queue[front];
        front++;
        return val;
    }
}
int bfs(int mat[v][v],int startnode){
    visited[startnode]=1;
    enqueue(startnode);

    while (front <= rear ){
        int node = dequeue();
        printf("%d ",node);
        for(int i=0;i<v;i++){
            if(mat[node][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i] =1;
            }
        }
    }

}


int main(){
    int mat[v][v] ={0} ;

    addEdge(mat,0,1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    printf("Adjacency Matrix Representation\n");
    display(mat);

    rear++ ;
    queue[rear] =0 ;

    bfs(mat,0);
    return 0 ;

}
