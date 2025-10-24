#include<stdio.h>
#define n 4 

int a[n][n]={
    {0,5,1,1},
    {3,2,1,0},
    {1,1,0,0},
    {2,0,0,3}
};
int b[n][n]={
    {1,7,3,0},
    {6,9,2,2},
    {8,4,2,0},
    {1,2,3,4}
};
int z[n][n];
void addmatrix(int a[n][n],int b[n][n],int z[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            z[i][j]=a[i][j]+b[i][j];
        }

    }

}
void submatrix(int a[n][n],int b[n][n],int z[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            z[i][j]=a[i][j]-b[i][j];
        }

    }

}
void strasen(int x[n][n],int y[n][n],int z[n][n],int size , int rowA, int colA,int rowB,int colB,int rowC,int colC){
    if(size==2){
 int a = x[rowA][colA];
        int b = x[rowA][colA+1];
        int c = x[rowA+1][colA];
        int d = x[rowA+1][colA+1];
        int e = y[rowB][colB];
        int f = y[rowB][colB+1];
        int g = y[rowB+1][colB];
        int h = y[rowB+1][colB+1];

        int m1 = (a + d) * (e + h);
        int m2 = (c + d) * e;
        int m3 = a * (f - h);
        int m4 = d * (g - e);
        int m5 = (a + b) * h;
        int m6 = (c - a) * (e + f);
        int m7 = (b - d) * (g + h);

        z[rowC][colC]     = m1 + m4 - m5 + m7;
        z[rowC][colC+1]   = m3 + m5;
        z[rowC+1][colC]   = m2 + m4;
        z[rowC+1][colC+1] = m1 - m2 + m3 + m6;
    }else{
        int mid =size/2;

        strasen(a,b,z,mid,rowA,colA,rowB,colB,rowC,colC);
        strasen(a,b,z,mid,rowA,colA+mid,rowB+mid,colB,rowC,colC);

        strasen(a,b,z,mid,rowA,colA,rowB,colB+mid,rowC,colC+mid);
        strasen(a,b,z,mid,rowA,colA+mid,rowB+mid,colB+mid,rowC,colC+mid);

        strasen(a,b,z,mid,rowA+mid,colA,rowB,colB,rowC+mid,colC);
        strasen(a,b,z,mid,rowA+mid,colA+mid,rowB+mid,colB,rowC+mid,colC);

        strasen(a,b,z,mid,rowA+mid,colA,rowB,colB+mid,rowC+mid,colC+mid);
        strasen(a,b,z,mid,rowA+mid,colA+mid,rowB+mid,colB+mid,rowC+mid,colC+mid);

    }
    
    
}
int main(){
    printf("\nProduct achieved using Strassen's algorithm: ");
    strasen(a,b,z,4,0,0,0,0,0,0);
    for(int i = 0; i < n ; i++) {
      printf("\n");
      for(int j = 0; j < n; j++)
         printf("%d\t", z[i][j]);
   }
    return 0;

}