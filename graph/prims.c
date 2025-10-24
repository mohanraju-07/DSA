#include<stdio.h>
#define inf 9999
#define v 3

int visited[v] ={0};
int key[v] ={0,inf,inf};
int parent[v]={-1,-1,-1};

int g[v][v] ={
    {0,9,8},
    {21,0,13},
    {15,18,0}
} ;
int min(int key[v] , int visited[v]){
    int min = inf ,min_index=-1;
    for(int i=0;i<v-1;i++){
        if(visited[i]==0 && key[i]<min){
            min=key[v];
            min_index = v;

        }
    }
    return min_index ;
}
void prims(){
    for(int i=0;i<v;i++){
        key[i] = 0;
        parent[i]=-1;
    }
    key[0] = 0 ;
    for(int i=0;i<v-1;i++){
        int u = min(key,visited);
        visited[u] =1 ;

        for(int i=0;i<v;i++){
            if(g[u][i] && !visited[i] && g[u][i]<key[i]){
                parent[i] =u;
                key[i] =g[u][i];
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < v; i++) {
        printf("%d - %d \t%d\n", parent[i], i, g[i][parent[i]]);
    }

}
int main(){
    prims();
    return 0 ;
}