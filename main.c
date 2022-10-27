#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;


struct node  *insert(struct node *root, int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->right = 0;
    newnode->data = x;  
    if(root == NULL){
        root = newnode;
    }
    if(x == -1){
        return root;
    }
    else{
        if(x < root->data){
            root->left=insert(root->left, x);
        }
        else if(x > root->data){
            root->right = insert(root->right,x);
        }

    }
    return root;
}


void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        printf("%d " , root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        printf("%d " , root->data);
        preorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        preorder(root->left);
        inorder(root->right);
        printf("%d " , root->data);
    }
}


int minVal(struct node *root){
    if(root->left == NULL){
        return root->data;
    }
    return minVal(root->left);
    
}



struct node *delete_(struct node *root, int x ){
    if(root == NULL){
        return root;
    }
    if(x < root->data){
        root->left=delete_(root->left,x);
        return root;
    }
    else if(x > root->data){
        root->right=delete_(root->right, x);
        return root;
    }
    else{
        printf("\nEqual ");
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        
        else if(root->left!=NULL && root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL&& root->right !=NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left !=NULL && root->right !=NULL){
            int min = minVal(root->left);
            root->data = min;
            root->right = delete_(root->right, min);
            return root;
        }
    }
}
int main(){
    int d;
    int key;
    printf("\n");
    while(d != -1){
        printf("Enter data " );
        scanf("%d", &d);
        root=insert(root, d);
    }
    printf("\nInorder traversal\n");
    inorder(root);
    printf("\nPostorder traversal\n");
    postorder(root);
    printf("\nPreorder traversal\n");
    preorder(root);
    printf("\nEnter data to delete: ");
    scanf("%d", &key);
    delete_(root, key);
    printf("\nAfter Deleton\n");
    inorder(root);
    return 0;
}