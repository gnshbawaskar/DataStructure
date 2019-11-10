//
//  main.c
//  DeletefromBST
//
//  Created by Apple on 10/11/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include <iostream>
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

//inorder successor
Node * MinValueNode(Node * root){
    
    Node *current = root;
    while(current&&current->left!=NULL)
        current=current->left;
    
    return current;
}

void InorderTraversal(Node *root){
    if (root==NULL)
        return;
    InorderTraversal(root->left);
    printf(" %d ",root->data);
    InorderTraversal(root->right);
}

Node * Delete(Node *root, int key){
    if(root == NULL)
        return root;
    else if (key < root->data)
        root->left = Delete(root->left, key);
    else if (key > root->data)
        root->right =  Delete(root->right, key);
    else{
        if (root->left == NULL&& root->right == NULL){
            delete root;
            root = NULL;
        }
        else if (root->left == NULL){
            Node * tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
        else if (root->right == NULL){
            Node * tmp = root;
            root = root->left;
            delete tmp;
            return root;
        }
        else //both child available
        {
            Node *tmp = MinValueNode(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }

    }
    
    return root;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Node *root;
    root = getNode(6);
    //       6
    //   3         12
    //1    5     10   15
    //   4     7  11    16
    
    root->left = getNode(3);
    root->right = getNode(12);
    root->left->left=getNode(1);
    root->left->right=getNode(5);
    root->right->left=getNode(10);
    root->right->right=getNode(15);
    root->left->right->left=getNode(4);
    root->right->left->left=getNode(7);
    root->right->left->right=getNode(11);
    root->right->right->right=getNode(16);
    
    Delete(root,10);
    InorderTraversal(root);
    return 0;
}
