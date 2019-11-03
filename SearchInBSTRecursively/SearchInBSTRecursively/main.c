//
//  main.c
//  SearchInBSTRecursively
//
//  Created by Apple on 02/11/19.
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

int FindNode(Node *root, int key){
    while(root!=NULL){
        
        if(root->data>key){
            return FindNode(root->left, key);
        }
        else if(root->data<key){
            return FindNode(root->right, key);
        }
        else{
            return 1;
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    Node *root;
    root = getNode(6);
    //       6
    //   3        12
    //1    5    10   15
    //   4     7  11    16
    //                      20
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
    root->right->right->right->right=getNode(20);
    if(FindNode(root, 70) == 1){
        printf("Element found in tree\n");
    }
    else{
        printf("Element not found in tree\n");
    }
    return 0;
}
