#include<stdio.h>
#include<string.h>

char exp[50];
char stack[25][50];
int top=-1;
char output[50] ;
int index=0;

int isoperator(char ch){
    if(ch=='+' || ch=='-' ||ch == '*'|| ch == '/' ||ch =='^'){
        return 1 ;
    }else{
        return 0 ;
    }
}

void revert(char ch[]){
    for(int i=0;i<strlen(ch);i++){
        if(isoperator(ch[i])){
            stack[top--]= output[index++];
            stack[top--]= output[index++];
        }else{
            stack[++top] =ch[i];
        }
    }

}

int main(){
    printf("Enter the postfix expression  ");
    scanf("%s",exp);
    revert(exp);
    for(int i=0;i<strlen(output);i++){
        printf("%s ",output[i]);
    }

    return 0;

}