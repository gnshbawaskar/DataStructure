//
//  main.c
//  FindMaxPathInMatrix
//
//  Created by Apple on 01/11/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
/*class Solution {
    
    int buffer[];
    static int top;
    public int rootsum(int[][] A, int i){
        int left=0;
        int right =0;
        
        int m = A.length;
        int n = A[0].length;
        int x = i/n;
        int y = i%n;
        if (i==m*n-1){
            return A[x][y];
        }
        
        if((i+1)%n == 0 && i !=0){
            right = 0;
            left = rootsum(A,i+n);
        }
        else if (i<n*m-1 && i>=(n*m-n)){
            left = 0;
            right = rootsum(A ,i+1);
        }
        else if(i>=0&&i<=n*m-n){
            left = rootsum(A,i+n);
            right = rootsum(A,i+1);
        }
        
        return (left > right ? left:right)+A[x][y];
    }
    
    
    public boolean PrintPath(int A[][], int sum, int i){
        boolean left=false;
        boolean right=false;
        int m = A.length;
        int n = A[0].length;
        int x=i/n;
        int y=i%n;
        
        if (i == n*m-1 && (sum-A[x][y])!=0 ){
            if ((sum-A[0][0]) == 0){
                buffer[top]= A[x][y];
                top++;
                return true;
            }
            
            return false;
        }
        
        if((i+1)%n == 0 && i !=0){
            
            if (i==n*m-1)
            {
                int j=(n*m-1)/n;
                int k=(n*m-1)%n;
                buffer[top]= A[j][k];
                top++;
                return true;
            }
            
            right = false;
            int j=(i+n)/n;
            int k=(i+n)%n;
            
            left = PrintPath(A,sum-A[j][k],i+n);
        }
        else if (i<n*m-1 && i>=(n*m-n)){
            left = false;
            int j=(i+1)/n;
            int k=(i+1)%n;
            
            right = PrintPath(A,sum-A[j][k],i+1);
        }
        else if(i>=0&&i<n*m-n){
            int j=(i+1)/n;
            int k=(i+1)%n;
            int d=(i+n)/n;
            int e=(i+n)%n;
            right = PrintPath(A,sum-A[j][k],i+1);
            left  = PrintPath(A,sum-A[d][e],i+n);
        }
        
        if (left || right){
            buffer[top]= A[x][y];
            top++;
        }
        
        return left || right;
    }
    
    
    public String solution(int[][] A) {
        buffer =  new int[100];
        
        int m = A.length;
        int n = A[0].length;
        if (n>1000||n==0||m==0||m>1000){
            return "";
        }
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                if( A[i][j] > 9||A[i][j]<1){
                    return "";
                }
            }
        }
        int sum = rootsum(A, 0);
        boolean ret = PrintPath(A,sum,0);
        
        int intPath[] = new int[1000];
        int count = 0;
        
        for (int j=top-1;j>=0;j--)
        {
            sum = sum - buffer[j];
            intPath[count] = buffer[j];
            if (sum==0)
            {
                intPath[++count] = buffer[++j];
                break;
            }
            count++;
        }
        
        String path = "";
        for(int h=0;h<count;h++){
            path =  String.format("%s%d", path,intPath[h]);
        }
        
        return path;// write your code in Java SE 8
    }
}*/
int N=3;
int M=4;
int save[100];
static int top;
int Findrootsum(int A[M][N], int n, int m, int i){
    int left =0;
    int right=0;
    
    if (i == n*m-1){
        return *(*A+i);
    }
    
    if((i+1)%n == 0 && i !=0){
        right = 0;
        left = Findrootsum(A,n,m,i+n);
    }
    
    else if (i<n*m-1 && i>=(n*m-n)){
        left = 0;
        right = Findrootsum(A,n,m ,i+1);
    }
    else if(i>=0&&i<=n*m-n){
        left = Findrootsum(A,n,m,i+n);
        right = Findrootsum(A,n,m ,i+1);
    }
    
    return (left > right ? left:right)+*(*A+i);
}


int  PrintPath(int A[M][N], int n, int m, int sum, int i){
    int left=0;
    int right=0;
    
    if (i == n*m-1 && (sum-*(*A+i))!=0 ){
        if ((sum-A[0][0]) == 0){
            //printf("\n%d", *(*A+i));
            save[top]= *(*A+i);
            top++;
            return 1;
        }
        
        return 0;
    }
    
    if((i+1)%n == 0 && i !=0){
        if (i==n*m-1)
        {
            save[top]= *(*A+i);
            top++;
            return 1;
        }
        
        right = 0;
        left = PrintPath(A,n,m,sum-*(*A+i+n),i+n);
        
    }
    else if (i<n*m-1 && i>=(n*m-n)){
        left = 0;
        right = PrintPath(A,n,m ,sum-*(*A+i+1),i+1);
    }
    else if(i>=0&&i<n*m-n){
        right = PrintPath(A,n,m ,sum-*(*A+i+1),i+1);
        left  = PrintPath(A,n,m,sum-*(*A+i+n),i+n);
    }
    
    if (left || right){
        save[top]= *(*A+i);
        top++;
    }
    
    return left || right;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int MM = 4;
    int NN = 3;
    int A[][3] =
//        {
//            {1,8,9},
//            {2,1,8},
//            {1,3,9}
//        };
    
            {   {9,9,7},
                {9,7,2},
                {6,9,5},
                {9,1,2}};
//        {   {5,5,4,1},
//            {1,3,2,2},
//            {2,9,5,3},
//            {4,6,9,8},
//            {3,6,7,8}
//        };
//    {   {5,6,8,9,1},
//        {1,8,2,1,2},
//        {2,9,5,3,4},
//        {3,1,8,7,6},
//        {1,2,3,4,5}
//    };
//      {
//         {5,6,8,9,2},
//         {1,8,9,1,4},
//         {2,9,5,3,6},
//         {3,1,8,7,1},
//         {4,2,3,9,3},
//         {5,6,4,6,3}};
    int sum = Findrootsum(A,NN,MM,0);
    printf("Sum:%d\n", sum);
    PrintPath(A,NN,MM,sum,0);
    
    
    char buffer[1000];
    int buf[1000];
    int count=0;
    
    for (int j=top-1;j>=0;j--){
        sum = sum - save[j];
        buf[count] = save[j];
        if (sum==0)
        {
            buf[++count] = save[++j];
            break;
        }
        count++;
        
    }
    
    for(int h=0;h<count;h++){
        sprintf(buffer, "%s%d", buffer,buf[h]);
    }
    
    printf("\nString:%s",buffer);

    return 0;
}
