#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int stack[50];
int top=-1;
char input[100];

bool checkBalanced(char input[]){
    top=-1;

    for(int i=0;i<strlen(input);i++){
        if(input[i]=='('){
            stack[++top] = input[i];
        }else if(input[i] == ')'){
            if(top==-1){
                return false ;
            }
            top--;
        }
    }
    return(top==-1) ;
}

int main(){
    printf("enter the input ");
    scanf("%s",input);
    if(checkBalanced(input)){
        printf("Balanced");
    }else{
        printf("not balanced");
    }

    return 0 ;
}