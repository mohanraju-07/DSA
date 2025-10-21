#include<stdio.h>
#include<string.h>

int maxsize =25 ;
int stack[25];
int top=-1 ;
char input[100];
char output[50] ;
char symbols[10] = {'+','-','*','/','^','(',')'};
char ch ;
int index=0;



int precedence(char ch){
    switch(ch){
        case '+' :
        case '-' : return 1 ;
        case '*' : 
        case '/' : return 2 ;
        case '^' : return 3 ;
        default : return 0 ;
    }
}
int isoperator(char ch){
    for(int i=0;i<strlen(symbols);i++){
        if(symbols[i]==ch){
            return 1 ;
        }
    }
    return 0 ;
}

int main()
{
    printf("Enter the input");
    scanf("%s",input);
    for(int i =0;i<strlen(input);i++){
        
        if(isoperator(input[i])){
            //int priority = precedence(input[i]);
            if(top == -1 || input[i]=='('){
                stack[++top] = input[i];
            }
            else{
                if(input[i]==')'){
                    while(top !=-1 && stack[top]!='('){
                        output[index++] =stack[top--];
                    }
                    top--;
                    continue;

                }
                if(precedence(input[i])<= precedence(stack[top])){
                    while(top != -1 && precedence(stack[top]) >= precedence(input[i])) {
                        output[index++] = stack[top--]; 
                    }
                    stack[++top] = input[i];    
                }else{
                    stack[++top] = input[i];
                }
            }

        }
        else{
            output[index++] =input[i];
        }
    }
    while(top!=-1){
        output[index++] = stack[top];
        top--;
    }
    output[index] = '\0';

    for(int i=0;i<strlen(output);i++){
        printf("%c",output[i]);
    }
    return 0;
}