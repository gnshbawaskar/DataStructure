//
//  main.c
//  MaxPathfromTRoot
//
//  Created by Apple on 26/10/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int buf[100];
static int top;
Node * getNode(int data){
    
    Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void printtree(Node *root){
    if(root == NULL)
        return;
    
    printtree(root->left);
    printf("%d ", root->data);
    printtree(root->right);
    
}

int  printPath(Node *root,int sum){
    if (sum ==0 ){
        return 1;
    }
    
    if(root == NULL)
        return 0;
    
    int left = printPath(root->left, sum-root->data);
    int right = printPath(root->right, sum-root->data);
    
    if (left || right){
         printf(" %d", root->data);
        buf[top]= root->data;
        top++;
    }
    
    
    return left || right;
}


int roottoleafsum(Node *root){
    if(root == NULL){
        return 0;
    }
    
    int left = roottoleafsum(root->left);
    int right= roottoleafsum(root->right);
    
    return (left > right ? left:right)+root->data;
}

void findmaxsumpath(Node *root){
    
    int sum=roottoleafsum(root);
    printf("\nMaximum Sum Is %d\n", sum);
    printPath(root, sum);
    
    for(int h=0;h<top;h++){
        printf("top:%d",buf[h]);
    }
    printf("\n");
    
}

void createTree(){
    Node *root;
    root = getNode(1);
    
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
    printtree(root);
    
    findmaxsumpath(root);
}

int NN=5;
int MM=5;

int RootSum(int A[MM][NN], int n, int m, int i){
    int left =0;
    int right=0;
    int x=i/n;
    int y=i%n;

    if (i == n*m-1){
        return A[x][y];
    }
    if((i+1)%n == 0 && i !=0){
       
        right = 0;
        left = RootSum(A,n,m,i+n);
    }
    
    else if (i<n*m-1 && i>=(n*m-n)){
        left = 0;
        right = RootSum(A,n,m ,i+1);
    }
    else if(i>=0&&i<=n*m-n){
        left = RootSum(A,n,m,i+n);
        right = RootSum(A,n,m ,i+1);
    }

    return (left > right ? left:right)+A[x][y];
}

int  PrintPath(int A[MM][NN], int n, int m, int sum, int i){
    int left=0;
    int right=0;
    int x=i/n;
    int y=i%n;

    if (i == n*m-1 && (sum-A[x][y])!=0 ){
        if ((sum-A[0][0]) == 0){
            buf[top]= *(*A+i);
            top++;
            return 1;
        }

        return 0;
    }
    int j=(i+1)/n;
    int k=(i+1)%n;
    int d=(i+n)/n;
    int e=(i+n)%n;
    if((i+1)%n == 0 && i !=0){
        
        if (i==n*m-1)
        {
            int j=(n*m-1)/n;
            int k=(n*m-1)%n;
            buf[top]= A[j][k];
            top++;
            return 1;
        }
        right = 0;
        left = PrintPath(A,n,m,sum-A[d][e],i+n);
    }
    else if (i<n*m-1 && i>=(n*m-n)){
        left = 0;
        right = PrintPath(A,n,m ,sum-A[j][k],i+1);
    }
    else if(i>=0&&i<n*m-n){
        right = PrintPath(A,n,m ,sum-A[j][k],i+1);
        left  = PrintPath(A,n,m,sum-A[d][e],i+n);
    }
    
    if (left || right){
        buf[top]= *(*A+i);
        top++;
    }
    
    return left || right;
}


int main(int argc, const char * argv[]) {
    printf("\n\n\n\n");
    int MM = 5;
    int NN = 5;
    int A[][5] =
//    {
//        {1,8,9},
//        {1,1,8},
//        {1,1,9}
//    };
//        {   {9,9,7},
//            {9,7,2},
//            {6,9,5},
//            {9,1,2}};
//    {   {5,5,4,1},
//        {1,3,2,2},
//        {2,9,5,3},
//        {4,6,9,8},
//        {3,6,7,8}
//    };
    {   {5,6,8,9,1},
        {1,8,2,4,2},
        {2,9,5,3,4},
        {3,1,8,7,6},
        {1,2,3,4,5}
    };
// {
//     {5,6,8,9,2},
//     {1,8,9,1,4},
//     {2,9,5,3,6},
//     {3,1,8,7,1},
//     {4,2,3,9,3},
//     {5,6,4,6,3}};


    int sum = RootSum(A,NN,MM,0);

    printf("Sum:%d\n", sum);
    int ret = PrintPath(A,NN,MM,sum,0);
    
    
    char buffer[1000];
    int b2[1000];
    int count=0;

    for (int j=top-1;j>=0;j--){
        sum = sum - buf[j];
        b2[count] = buf[j];
        if (sum==0)
        {
            b2[++count] = buf[++j];
            break;
        }
        count++;
        
    }
    
    for(int h=0;h<count;h++){
       
        sprintf(buffer, "%s%d", buffer,b2[h]);
    }
    printf("\nString:%s",buffer);

    return 0;
}
