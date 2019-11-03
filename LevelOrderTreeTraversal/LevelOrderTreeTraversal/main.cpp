//
//  main.c
//  LevelOrderTreeTraversal
//
//  Created by Apple on 03/11/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
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

void LevelOrderTreeTraversal(Node *root){
    if (root == NULL)
        return;
    queue<Node *> queue;
    queue.push(root);
    
    while(queue.empty() == false){
        
        Node *nd = queue.front();
        queue.pop();
        int i = nd->data;
        printf(" %d", i);
        if(nd->left)
            queue.push(nd->left);
        if(nd->right)
            queue.push(nd->right);
        }
}

int main(int argc, const char * argv[]) {
    Node *root;
    root = getNode(1);
    //       1
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
    LevelOrderTreeTraversal(root);
    return 0;
}
