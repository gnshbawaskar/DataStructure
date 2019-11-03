//
//  main.c
//  NonRecursivePreorderTraversal2
//
//  Created by Apple on 03/11/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
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

void PreorderTraversal(Node *root){
    if (root==NULL)
        return;
    
    stack<Node *> stack;
    stack.push(root);
    while(stack.empty() == false){
        
        Node *nd = stack.top();
        stack.pop();
        
        printf(" %d", nd->data);
        
        if(nd->right)
            stack.push(nd->right);
        if (nd->left)
            stack.push(nd->left);
    }
}


int main(int argc, const char * argv[]) {
    Node *root;
    root = getNode(1);
    //    1
    //   2       3
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
    
    PreorderTraversal(root);
    return 0;
}
