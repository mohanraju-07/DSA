#include <stdio.h>
#define max 6

struct edge {
    int src;
    int dest; 
    int weight ;
};
int graph[max][max]={
    {0,13,0,0,0,10},
    {13,0,5,0,3,0},
    {0,5,0,6,7,0},
    {0,0,6,0,9,0},
    {0,3,7,9,0,24},
    {10,0,0,0,24,0}
};
int parent[max] ;

struct edge* create(){
    
}