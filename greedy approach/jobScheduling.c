#include<stdio.h>
#define n 5
char jobs[n] ={'a','b','c','d','e'};
int deadlines[n] = {2,2,1,3,4};
int profits[n]={20,60,40,100,80} ;
int max;

void maxd() {
    max = deadlines[0];
    for (int i = 1; i < n; i++) {
        if (deadlines[i] > max)
            max = deadlines[i];
    }
}
void job(){
    maxd();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(profits[j]<profits[j+1]){
                int temp =profits[j];
                profits[j] =profits[j+1];
                profits[j+1] =temp ;

                int t = deadlines[j];
                deadlines[j]=deadlines[j+1];
                deadlines[j+1] =t;

                int temp2 =jobs[j];
                jobs[j] =jobs[j+1];
                jobs[j+1] = temp2;

            }
        }
    }
    int total=0;
    int slot[max];
    char result[max] ;

    for (int i = 0; i < max; i++)
        slot[i] = 0;
    for(int i=0;i<n;i++){
        for(int j=deadlines[i]-1;j>=0;j--){
            if(slot[i]==0){
                result[j] = jobs[i];
                slot[j] = 1;
                total += profits[i];
                break;
            }
        }
    }

     printf("Selected job sequence: ");
    for (int i = 0; i < max; i++) {
        if (slot[i])
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit = %d\n", total);

    
}
int main(){
    job();
    return 0;

}