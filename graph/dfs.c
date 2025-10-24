#include<stdio.h>
#define v 4 

int visited[v] ={0};

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
void dfs(int mat[v][v], int node){
    visited[node]=1;
    printf("%d ",node) ;
    for(int i=0;i<v;i++){
            if(mat[node][i] ==1 && visited[i] ==0)
                dfs(mat,i) ;
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

    dfs(mat,0);

    return 0 ;

}