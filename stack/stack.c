#include<stdio.h>
#include<stdlib.h>

int maxsize=10;
int stack[10];
int top=-1 ;

int push(int data){
    if(top< maxsize-1){
        top++;
        stack[top] = data ;
    }
    else {
        printf("size full");
    }

}
int pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        int popped = stack[top];
        top--;
        return popped;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main(){
    push(12);
    push(2);
    push(34);
    push(43);
    push(23);
    display();
    printf("\nafter poping\n");
    pop();
    pop();
    pop();
    pop();

    display();
    return 0;
}