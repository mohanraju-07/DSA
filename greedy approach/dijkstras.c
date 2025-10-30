#include<stdio.h>
#define max 5 
#define inf 9999999

int visited[max]={0};
int parent[max]={-1};
int dist[max] = {inf};

int graph[max][max] ={
    {inf,15,inf,inf,16},
    {15,inf,6,inf,inf},
    {inf,6,inf,7,inf},
    {inf,inf,7,inf,10},
    {16,inf,inf,10,inf}
};
int minfinder(int startnode){
    int min=inf;
    int minindex;
    for(int i=0;i<max;i++){
        if(dist[i]<min && visited[i]==0){
            min= dist[i];
            minindex= i;
        }
    }
    return minindex;
}
void dijkstra(int startnode){
    for(int i=0;i<max;i++){
        visited[i]=0;
        dist[i]=inf;
        parent[i]=-1;
    }
    dist[startnode]=0;
    for(int count=0;count<max-1;count++){
        int min = minfinder(startnode);
        if(min==-1){
            break ;
        }
        visited[min]=1;

        for(int v=0;v<max;v++){
            if(!visited[v]&& graph[min][v]!=inf && (dist[min]+graph[min][v]< dist[v])){
                dist[v]= dist[min]+graph[min][v];
                parent[v]=min;
            }
        }           
    }
}


void printPath(int v) {
    if (v == -1) return;
    printPath(parent[v]);
    printf("%d ", v);
}

int main() {
    int start = 0;
    dijkstra(start);

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < max; i++) {
        printf("%d\t%d\t\t", i, dist[i]);
        printPath(i);
        printf("\n");
    }

    return 0;
}