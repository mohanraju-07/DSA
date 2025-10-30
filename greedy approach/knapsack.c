#include<stdio.h>
#define n 7
#define size 15
int profits[n] = {10,5,15,7,6,18,3};
int weights[n] = {2,3,5,7,1,4,1};

void knapsack() {
    float p_w[n];

    for (int i = 0; i < n; i++) {
        p_w[i] = (float)profits[i] / weights[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p_w[j] < p_w[j + 1]) {

                float temp = p_w[j];
                p_w[j] = p_w[j + 1];
                p_w[j + 1] = temp;

                int t1 = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = t1;

                int t2 = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = t2;
            }
        }
    }
    float total=0 ;
    int remaining=size ;
    for(int i=0;i<n;i++){
        if(weights[i]<=remaining){
            remaining-=weights[i];
            total+=profits[i];
        }
        else{
            total +=profits[i]*((float)remaining/weights[i]) ;
            break ;
        }
    }
    

    printf("Profit  Weight  P/W\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%.2f\n", profits[i], weights[i], p_w[i]);
    }
    printf("Total profit : %.2f",total);
}

int main() {
    knapsack();
    return 0;
}
