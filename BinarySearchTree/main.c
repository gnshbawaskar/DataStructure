//
//  main.c
//  BinarySearchTree
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

Node * SearchInBinaryTree1(Node *root, int key){
    if(root == NULL)
        return root;
    
    if(root->data==key){
        return root;
    }
    else if (root->data > key){
        return SearchInBinaryTree1(root->left, key);
    }
    else{
        return SearchInBinaryTree1(root->right, key);
    }
    
    return NULL;
}

Node * SearchInBinaryTree2(Node *root, int key){

    while(root!= NULL)
    {
        if(root->data==key){
            return root;
        }
        else if (root->data > key){
            root = root->left;
        }
        else if(root->data < key){
            root = root->right;
        }
    }
    return NULL;
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
    
    Node *nd = SearchInBinaryTree1(root, 10);
    if (nd){
        printf("Key Node Found:%d\n", nd->data);
    }
    else{
        printf("Key node not found\n");
    }
    return 0;
}
