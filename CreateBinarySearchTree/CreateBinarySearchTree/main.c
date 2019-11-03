//
//  main.c
//  CreateBinarySearchTree
//
//  Created by Apple on 01/11/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node * getNode(int key){
    Node *node = (Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL;
    node->right= NULL;
    return node;
}

void InorderTraversal(Node *root){
    if (root==NULL)
        return;
    InorderTraversal(root->left);
    printf(" %d ",root->data);
    InorderTraversal(root->right);
}

void InsertBSTTree(Node **root,int key){
    if (*root==NULL){
        *root = getNode(key);
        return;
    }
    
    Node *temp = *root;
    Node *prev = NULL;
    while (temp!=NULL)
    {
        prev = temp;
        if(temp->data>key){
            temp = temp->left;
        }
        else if(prev->data<key){
            temp = temp->right;;
        }
    }
    
    Node *nd = getNode(key);
    if (prev->data > nd->data){
        prev->left= nd;
    }
    else{
        prev->right= nd;
    }
}

int main(int argc, const char * argv[]) {
    Node *root = NULL;
    //1/2/3/6/9/10/11
    InsertBSTTree(&root, 6);
    InsertBSTTree(&root, 10);
    InsertBSTTree(&root, 2);
    InsertBSTTree(&root, 3);
    InsertBSTTree(&root, 1);
    InsertBSTTree(&root, 9);
    InsertBSTTree(&root, 11);
    
    InorderTraversal(root);
    return 0;
}
