#include <stdio.h>
#define max 6
#define inf 9999

int mat[max][max] = {
    {0,13,0,0,0,10},
    {13,0,5,0,3,0},
    {0,5,0,6,7,0},
    {0,0,6,0,9,11},
    {0,3,7,9,0,24},
    {10,0,0,11,24,0}
};

int visited[max];
int n = 6;
int minCost = inf;
int path[max], bestPath[max];

void tsp(int city, int count, int cost, int start) {
    path[count - 1] = city;  // store current city

    // base case: all cities visited and can return to start
    if (count == n && mat[city][start] > 0) {
        int total = cost + mat[city][start];
        if (total < minCost) {
            minCost = total;
            for (int k = 0; k < n; k++)
                bestPath[k] = path[k];
        }
        return;
    }

    // try all next cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && mat[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, cost + mat[city][i], start);
            visited[i] = 0; // backtrack
        }
    }
}

int main() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0, 0);

    printf("Minimum cost of TSP route: %d\n", minCost);
    printf("Best path: ");
    for (int i = 0; i < n; i++)
        printf("%d -> ", bestPath[i]);
    printf("0\n"); // back to start
    return 0;
}
