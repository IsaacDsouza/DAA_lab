//diameter of bt

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;

};
struct Node* newNode(int data);
int max(int a, int b);
int height(struct Node *node);
int diameter(struct Node *tree);

int max(int a, int b){
    return (a>=b)?a:b;
}
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
}

int height(struct Node *node){
    if(node==NULL){
        return 0;
    }
    
    return 1 + max(height(node->left),height(node->right));
}

int diameter(struct Node *tree){
    if(tree==NULL)
        return 0;
    
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter= diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight+rheight+1, max(ldiameter,rdiameter));    
}
int main() 
{
	struct Node *root = newNode(1); 
	root->left        = newNode(2); 
	root->right       = newNode(3); 
	root->left->left  = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left  = newNode(8);
	root->left->left->right  = newNode(9); 

	printf("Diameter of the given Binary Tree is %d\n", diameter(root)); 
} 
