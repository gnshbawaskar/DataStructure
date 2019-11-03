//
//  main.c
//  TreeTraversal
//
//  Created by Apple on 30/10/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;


Node * getNode(int data){
    
    Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void InorderTraversal(Node *root){
    if (root==NULL)
        return;
    InorderTraversal(root->left);
    printf(" %d ",root->data);
    InorderTraversal(root->right);
}

void PreorderTraversal(Node *root){
    if (root==NULL)
        return;
    
    printf(" %d ",root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void PostorderTraversal(Node *root){
    if (root==NULL)
        return;
    
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf(" %d ",root->data);
}

int main(int argc, const char * argv[]) {
    Node *root;
    root = getNode(1);
        //  1
       //2       3
    //8    4   5   6
    //   10  7  9     5
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left=getNode(8);
    root->left->right=getNode(4);
    root->right->left=getNode(5);
    root->right->right=getNode(6);
    
    root->left->right->left=getNode(10);
    root->right->left->left=getNode(7);
    root->right->left->right=getNode(9);
    root->right->right->right=getNode(5);
    InorderTraversal(root);
    
    return 0;
}
