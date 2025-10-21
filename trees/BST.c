#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data ;
    struct tree* left ;
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
struct tree * insert(struct tree* root ,int data){
    if(root==NULL){
        return create(data);
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    }
    if(data>root->data){
        root->right =insert(root->right,data);
    }
    return root ;
}

int main(){
        int rootno, num, n;

    printf("Enter the root node: ");
    scanf("%d", &rootno);

    struct tree* root = create(rootno);

    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &num);

    printf("Enter %d node values:\n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &n);
        root = insert(root, n);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
}