#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tree{
    int data ;
    struct tree * left ;
    struct tree * right ;
};

struct tree * create(int data){
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL ;
    return node ;
}

void inorder(struct tree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

bool checkFBT(struct tree* root){
    if(root==NULL) {
        return true ;
    }
    if(root->left==NULL && root->right==NULL)
        return true ;
    if(root->left !=NULL && root->right!=NULL){
        return checkFBT(root->left) && checkFBT(root->right);

    }
    else{
        return false ;
    }
    

}
int main(){
    struct tree* root = create(20);
    root->left = create(10);
    root->right =create(25) ;
    root->left->right =create(15);
    root->left->left=create(6);
    if(checkFBT(root)){
        printf("its a full binary tree");
    }
    else{
        printf("its not a full binary tree");
    }
    //inorder(root)
    return 0 ;
}