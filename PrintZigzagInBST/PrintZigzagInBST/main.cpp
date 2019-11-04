//
//  main.c
//  PrintZigzagInBST
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

void printZigZag(Node *root){
    if(root==NULL){
        return;
    }
    
    stack<Node *> stack1,stack2;
    stack1.push(root);
    int toggle=1;
    while(stack1.empty()==false||stack2.empty()==false)
    {
        if (toggle==1){
            Node * nd = stack1.top();
            stack1.pop();
            printf(" %d", nd->data);
            if (nd->left)
                stack2.push(nd->left);
            if (nd->right)
                stack2.push(nd->right);
        }
        else{
            Node * nd = stack2.top();
            stack2.pop();
            printf(" %d", nd->data);
            if (nd->right)
                stack1.push(nd->right);
            if (nd->left)
                stack1.push(nd->left);
         
        }
        if (stack1.empty()==true){
            toggle = 0;
            
        }
        if (stack2.empty()==true){
            toggle = 1;
        }
    }
}
int main(int argc, const char * argv[]) {
    Node *root;
    root = getNode(6);
    //       6
    //   3        12
    //1    5    10   15
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

    printZigZag(root);
    return 0;
}
