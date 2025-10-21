#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
int max (int a, int b){
    return (a>b)?a:b ;
}

int height(struct tree* root ){
    if(root==NULL){
        return 0 ;
    }
    int leftsubtree = height(root->left);
    int rightsubtree = height(root->right);

    int ht = 1+max(leftsubtree,rightsubtree);
    return ht;

}

void inorder(struct tree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct tree* rightrotate(struct tree* node){
    struct tree* x = node->left;
    struct tree* t2 = x->right ;

    x->right = node ;
    node->left = t2 ;

    return x ;

}

struct tree* leftrotate(struct tree* node){
    struct tree* y = node->right;
    struct tree * t2= y->left ;

    y->left = node ;
    node->right = t2 ;

    return y ;
}
struct tree * insert(struct tree* root ,int data){
    if(root==NULL){
        return create(data);
    }

    if(data < root->data){
        root->left = insert(root->left,data);
    } else if(data>root->data){
        root->right =insert(root->right,data);
    } else {
        return root; // duplicates not allowed
    }

    int bf = height(root->left) - height(root->right);
    //printf("the BF of %d is %d \n", root->data, bf);

    // LL Case
    if(bf >1 && data < root->left->data){
        return rightrotate(root);
    }
    // RR Case
    if(bf <-1 && data>root->right->data){
        return leftrotate(root) ;
    }
    // LR Case
    if(bf >1 && data > root->left->data){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    // RL Case
    if(bf <-1 && data <root->right->data){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
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

    printf("the neight of the tree is:%d ",height(root));
}