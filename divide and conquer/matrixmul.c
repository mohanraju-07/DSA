#include<stdio.h>
#define s 8
int a[s][s] ={
    {1,2,0,1,3,1,2,0},
    {4,0,1,2,1,0,2,1},
    {3,1,2,0,2,1,0,3},
    {0,2,1,1,1,2,1,0},
    {1,0,3,2,0,1,2,1},
    {2,1,0,1,3,0,1,2},
    {0,2,1,0,2,1,1,0},
    {1,0,2,1,0,2,1,1}
};
int b[s][s] ={
    {0,1,2,1,0,1,2,0},
    {2,0,1,0,2,1,0,1},
    {1,2,0,1,1,0,1,2},
    {0,1,2,0,1,2,0,1},
    {1,0,1,2,0,1,2,0},
    {2,1,0,1,2,0,1,1},
    {1,0,2,1,0,2,1,0},
    {0,1,0,2,1,0,2,1}
};
int c[s][s];

void multiply(int a[s][s],int b[s][s],int c[s][s],int size,int rowA,int colA,int rowB,int colB,int rowC,int colC){
    if(size==2) {
        c[rowC][colC]     = a[rowA][colA]*b[rowB][colB] + a[rowA][colA+1]*b[rowB+1][colB];
        c[rowC][colC+1]   = a[rowA][colA]*b[rowB][colB+1] + a[rowA][colA+1]*b[rowB+1][colB+1];
        c[rowC+1][colC]   = a[rowA+1][colA]*b[rowB][colB] + a[rowA+1][colA+1]*b[rowB+1][colB];
        c[rowC+1][colC+1] = a[rowA+1][colA]*b[rowB][colB+1] + a[rowA+1][colA+1]*b[rowB+1][colB+1];
    }
    else{
        int mid= size/2;
        multiply(a,b,c,mid,rowA,colA,rowB,colB,rowC,colC);
        multiply(a,b,c,mid,rowA,colA+mid,rowB+mid,colB,rowC,colC);

        multiply(a,b,c,mid,rowA,colA,rowB,colB+mid,rowC,colC+mid);
        multiply(a,b,c,mid,rowA,colA+mid,rowB+mid,colB+mid,rowC,colC+mid);

        multiply(a,b,c,mid,rowA+mid,colA,rowB,colB,rowC+mid,colC);
        multiply(a,b,c,mid,rowA+mid,colA+mid,rowB+mid,colB,rowC+mid,colC);

        multiply(a,b,c,mid,rowA+mid,colA,rowB,colB+mid,rowC+mid,colC+mid);
        multiply(a,b,c,mid,rowA+mid,colA+mid,rowB+mid,colB+mid,rowC+mid,colC+mid);

    }
   
}


int main() {
    // Initialize c matrix to 0
    for (int i=0; i<s; i++)
        for (int j=0; j<s; j++)
            c[i][j] = 0;

    multiply(a, b, c, s, 0, 0, 0, 0, 0, 0);

    printf("Result matrix C:\n");
    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    return 0;
}