//1). Write a program to construct a binary tree to support the following operations.
//assume no duplicate elements while constructing the tree.
//i. Given a key, perform a search in the binary search tree. If the key is found 
//then display “key found” else insert the key in the binary search tree.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;

};

struct Node *createNode(int key){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->key=key;
    newNode->left=newNode->right=NULL;
    return newNode;

}
void searchInsert(struct Node** root, int key){
    if (*root==NULL){
        *root = createNode(key);
        printf("Key inserted \n");
        return;

    }
    if (key==(*root)->key){
        printf("Key found \n");
        
    }else if(key<(*root)->key){
        searchInsert(&((*root)->left),key);
    }else {
        searchInsert(&((*root)->right),key);

    }
}
int main(){
    struct Node* root =NULL;
    int keys[]={50,30,20,40,70,60,80};
    int numKeys=sizeof(keys)/sizeof(keys[0]);
    for(int i=0;i<numKeys;i++){
        searchInsert(&root,keys[i]);


    }
    int searchKey=60;
    searchInsert(&root,searchKey);
    return 0;
}


