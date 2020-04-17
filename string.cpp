//
//  main.m
//  StringCopy
//
//  Created by Apple on 12/02/20.
//  Copyright © 2020 Apple. All rights reserved.
//
#import <Foundation/Foundation.h>

int strcat(int n){
    int count =0;
    for(int i=0;i<32;i++){
        if ((1<<i & n)){
            count++;
        }
    }
    
    return count;
}


char * stringcopy(char *str1,char *str2){
    
     long int len = strlen(str1);
    
    str2 = (char *)malloc(sizeof(char)*(len+1));
    char *tmp = str2;
    
    while(*str1!='\0'){
        printf("%c\n", *str1);
        *tmp=*str1;
        str1++;
        tmp++;
    }
    
    *tmp = '\0';
    return str2;
}

int funcSum(int n){
    
    if (n/10==0){
        return n;
    }
            
    return funcSum(n/10) + n%10;
}

void binary(int n){
    
    if (n/2==0){
        printf("%d",n);
        return;
        
    }
    binary(n/2);
    printf("%d",n%2);
}

int strlengh(char *str){
    int length=0;
    while(*str!='\0'){
        length = length+1;
        str++;
    }
    
    return length;
}

char * reverseString(char *str){
    long int len = strlen(str);
    int lt = len-1;
    char tmp;
    for(int i=0;i<len/2;i++,lt--){
        tmp = str[i];
        str[i] = str[lt];
        str[lt]=tmp;
    }
    
    return str;
}


bool binarysearch(int *arr, int key ,int len){
    int max=len-1;
    int min=0;
    int mid;
    while(max>=min){
        mid = min +(max-min)/2;
        
        if (arr[mid] == key){
            return true;
        }
        else if (arr[mid] > key){
           max = mid-1;
        }
        else if(arr[mid] < key){
           min=mid+1;
        }
    }
    return false;
}

bool oddEven(int n){
    
    if (1&n){
        return false;
    }
    else
        return true;
    
}

void togglebit(int n, int m){
    binary(n);
    int x=(1<<m);
    int y=n^x;
    printf("\n");
    binary(y);
}

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * newNode(int data){
    struct node *temp = (struct node * )malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
static int count;
void inorder(struct node *root){
    if (root == NULL){
        return;
    }
    if(root->left!=NULL && root->right!=NULL)
   {
       count++;
   }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder1(struct node *root){
    if (root == NULL){
        return;
    }
    
    printf("%d ",root->data);
    preorder1(root->left);
    preorder1(root->right);
}
void postOrder(struct node *root){
    if (root == NULL){
        return;
    }

    preorder1(root->left);
    preorder1(root->right);
    printf("%d ",root->data);
}

bool search(int key, struct node *root){
    while(root != NULL){
        
        if (root->data == key){
            return true;
        }
        else if (root->data>key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return false;
}

void insert(int key, struct node *root){
    struct node *temp=root;
    struct node *prev=NULL;
    
    if (root == NULL){
        root = newNode(key);
        return;
    }
    
    while(temp != NULL){
        prev = temp;
        if (temp->data>key){
            
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    
    if (prev->data>key)
        prev->left = newNode(key);
    else
        prev->right = newNode(key);
}

void fab(int n){
    int count1 = 0;
    int count2 = 1;
    int total;
    for (int i=0;i<n;i++){
        
        total = count1+count2;
        count1 = count2;
        count2 = total;
        printf(" %d", total);
    }
    
}

int countZero(int n){
    binary(n);
    int count =0;
    int count1=0;
    int prev=0;
    for(int i=0;i<5;i++){
        if (!(1<<i & n)){
            count++;
            if (count1%2==0){
                if (prev<count){
                    prev = count;
                }
                count=0;
            }
        }
        else{
            count1++;
        }
    }
    
    return prev;
}


int countOne(int n){
    int count =0;
    for(int i=0;i<32;i++){
        if ((1<<i & n)){
            count++;
        }
    }
    
    return count;
}

int countZero1(int n){
    binary(n);
    int count=0;
    while(n>0){
        count = count + !(n&1);
        n=n>>1;
    }
    return count;
}

void writefile(){
FILE *fp;
  
fp=fopen("/Users/apple/Desktop/myfile2.txt","a+");
fputs("hello c programming",fp);

fclose(fp);
}
void writefileputc(){
FILE *fp;
  
fp=fopen("/Users/apple/Desktop/myfile2.txt","a+");
    char name[20]= "Ganesh bawaskar";
    
    for(int i=0;i<strlen(name);i++){
        fputc(name[i],fp);
    }

fclose(fp);
}
void readfile(){
    FILE *fp;
    char text[300];
    char ch;
    int count=0;
    fp=fopen("/Users/apple/Desktop/myfile2.txt","r");
    //printf("%s",fgets(text,200,fp));
    while((ch=fgetc(fp))!= EOF){
        if (ch == ' '|| ch == '\n')
            count++;
        //printf("%c ", ch);
    }
    fclose(fp);
}
int M=3;
int N=3;
void twodimentionalarr(int arr[M][N]){
    
    for (int i=0;i<M;i++){
        
        for (int j=0;j<N;j++){
            printf("%d ", arr[i][j]);
        }
    }
}


void twodimentionalarr1(int m, int n, int arr[][n]){
    
    for (int i=0;i<M;i++){
        
        for (int j=0;j<N;j++){
            printf("%d ", arr[i][j]);
        }
    }
}


void reverseNumber(int n){
    int sum=0;
    while (n>0){
        sum=sum*10+n%10;
        n=n/10;
    }
    
    printf("%d", sum);
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
      //  insert code here...
      //  NSLog(@"Hello, World!");
    }
    char *tmp=NULL;
    char *str1= "ganesh";
    // tmp = stringcopy(str1,tmp);
    
    //printf("%s", tmp);
    
     //  printf("\n%d", funcSum(3323));
    char *str = malloc(sizeof(char)*6);
    strcpy(str, "ganesh");
    //printf("%s", reverseString(str));
    //binary(7);
    int arr [10] = {11,22,33,44,55,66,77,88,99,110};

   // bool ret = binarysearch(arr,77, 10);
    //bool ret = oddEven(11);
    //togglebit(9,0);
    
    struct node *root = newNode(10);
    root->left=newNode(5);
    root->right=newNode(20);
    root->left->left=newNode(3);
    root->left->right=newNode(8);
    root->right->left=newNode(12);
    root->right->right=newNode(25);
    root->right->right->left=newNode(22);
    root->right->right->right=newNode(30);
    
    //bool ret = search(222,root);
    
    //preorder1(root);
    //postOrder(root);
    struct node *root1 = newNode(10);
    insert(5,root1);
    insert(20,root1);
    insert(3,root1);
    insert(8,root1);
    insert(12,root1);
    insert(25,root1);
    insert(22,root1);
    insert(30,root1);
    //inorder(root1);
    //fab(7);
    //int ret =countZeroAnOne(19);
    //binary(19);
    //printf("\n%d", countZero(24));
    //countOne(7);
    //writefile();
    //readfile();
    //writefileputc();
    //int arr1[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    //twodimentionalarr1(3,3,arr1);
   reverseNumber(1234);
    return 0;
}
