#include<stdio.h>
#include<string.h>
#include<math.h>

int x;
int y;
int length(int d){
    int count=0 ;
    if(d==0) 
        return 1;
    while(d!=0)
    {   
        d=d/10 ;
        count++;
    }
    return count;
}
int countDigits(int num) {
    if (num == 0) return 1;
    return (int)log10(num) + 1;
}
int max(int a,int b){
    return (a>b)?a:b ;
}
int karatsuba(int x , int y){
    if(x<10 || y<10){
        return x*y ;
    }
    int m = max(length(x),countDigits(y)) /2;
    int b = x % (int)pow(10,m);
    int a = (x /(int)pow(10,m));
    int d = y % (int)pow(10,m);
    int c = (y /(int)pow(10,m));

    int p1 = karatsuba(a,c);
    int p2 =karatsuba(b,d);
    int p3 =karatsuba(a+b,c+d);

    int middle = p3-p2-p1 ;
    
    return (int)pow(10,2*m)*p1 +(int)pow(10,m)*middle +p2 ;   
}
int main(){

    printf("enter the first number :");
    scanf("%d",&x);
    printf("enter the second number: ");
    scanf("%d",&y);
    int result = karatsuba(x,y);
    printf("result is :%d",result);
    return 0;

}