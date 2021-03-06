//
//  main.c
//  HeightOftree
//
//  Created by Apple on 01/11/19.
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

int HeightOfTree(Node *root){
    
    if (root == NULL)
        return 0;
    
    int left = HeightOfTree(root->left);
    int right = HeightOfTree(root->right);
    
    if(left>right)
        return left + 1;
    else
        return right + 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Node *root;
    root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(8);
    root->left->right = getNode(4);

    root->right->left = getNode(5);
    root->right->right = getNode(6);
    
    root->left->right->left = getNode(10);
    root->right->left->left = getNode(7);
    root->right->left->right = getNode(9);
    root->right->right->right = getNode(5);

                               // 1
                          //2             3
                       //8     4       5     6
    //                      10       7   9       5
    int height = HeightOfTree(root);
    printf("Height:%d\n",height);
    return 0;
}
