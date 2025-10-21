#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data ;
    struct tree* left;
    struct tree* right ;
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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct tree* root){
    int ht =0 ;
    if (root == NULL){
        return 0 ;
    }
    int leftsubtree =height(root->left);
    int rightsubtree = height(root->right);

    ht =1+ max(leftsubtree,rightsubtree);
    return ht;
}

int lvl(int data , struct tree* root){
    if (root == NULL)
        return 0;

    if(root->data ==data)
        return 1 ;
    int leftsubtree = lvl(data,root->left);
    int rightsubtree = lvl(data,root->right);

    if(leftsubtree!=0){
        return leftsubtree+1 ;
    }
    if(rightsubtree!=0){
        return rightsubtree+1 ;
    }

    return 0 ;
}

void allleafnodes(struct tree* root){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        printf("%d " ,root->data);
        return ;
    }
    allleafnodes(root->left);
    allleafnodes(root->right);
}
int main(){
    struct tree* root = create(20);
    root->left = create(10);
    root->right =create(25) ;
    root->left->right =create(15);
    root->left->right->left = create(30);
    //inorder(root);
        int h = height(root);
    //printf("\nHeight of the tree: %d", h);

    int l = lvl(25,root);
    //printf("the level of %d is : %d",25,l);
    allleafnodes(root);

    return 0 ;
}