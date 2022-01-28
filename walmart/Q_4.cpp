#include <iostream>
#include "bits/stdc++.h"
using namespace std ;
#define MAX 10

/*
 link : https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/
 finding uique paths question
 1.recusion
 2.top-down
 3.bottom-up

*/
int unique_paths_1(int row,int col,int max_row,int max_col){
    //base cases
    if(row>=max_row || col>=max_col) return 0 ;
    //desried result
    if(row == max_row-1 && col == max_col-1) return 1 ;
    //down row+1 and right col+1

    return (unique_paths_1(row+1,col,max_row,max_col) + unique_paths_1(row,col+1,max_row,max_col)) ;
    /*
    time : O(2^N)
    space : O(N) recursive stack
    */

}
int dp[MAX][MAX] ;
int unique_paths_2(int row,int col,int max_row,int max_col){
    //memorization
    //base case
    if(row>=max_row || col>=max_col) return  0;

    if(dp[row][col]!=-1) return dp[row][col] ;
    
    if(row == max_row-1 && col == max_col-1) return 1 ;

    return dp[row][col] = (unique_paths_2(row+1,col,max_row,max_col) + unique_paths_2(row,col+1,max_row,max_col)) ;

    /*
    time : O(N^2) //we reach n*m cells only once second time we take that value from hashtable
    space : O(N*M) + O(N) hashtable + recursive stack
    */

}
int unique_paths_3(int row,int col,int max_row,int max_col){
    //bottom-up
    int dp_1[max_row][max_col] ;
    //base conditions
    for(int i = 0;i<max_row;i++){
        dp_1[i][0] = 1;
    }
    for(int i = 0;i<max_col;i++){
        dp_1[0][i] = 1 ;
    }

    for(int i = 1;i<max_row;i++){
        for(int j = 1;j<max_col;j++){
            dp_1[i][j] = dp_1[i-1][j] + dp_1[i][j-1] ;
        }
    }

    return dp_1[max_row-1][max_col-1] ;
    /*
    time : O(N^2)
    space : O(N*M)
    */
}

int main(){
    //for memorization
    memset(dp,-1,sizeof(dp)) ;
    cout<<unique_paths_1(0,0,3,3)<<endl;
    cout<<unique_paths_2(0,0,3,3)<<endl ;
    cout<<unique_paths_3(0,0,3,3)<<endl;
    return 0;
}