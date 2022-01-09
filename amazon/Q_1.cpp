#include <iostream>
#include "bits/stdc++.h"
#define MAX 100
using namespace std;
/*
link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
In the stock market, a person buys a stock and sells it on some future date.
 Given the stock prices of N days in an array A[ ] and a positive integer K, 
 find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to 
(buying + selling) of a stock and new transaction can start only when the previous transaction has been completed

*/
//using recursion
int recur_helper(bool isbuy,int pos,int arr[],int n,int k){
    //base case
    if(pos == n || (isbuy && pos == n-1) || k == 0){
        return 0;
    }
    int profit = 0;
    //skipping this transaction
    int skip = recur_helper(isbuy,pos+1,arr,n,k);

    if(isbuy){
        //buying case
        profit = recur_helper(false,pos+1,arr,n,k)-arr[pos];
    }
    else{
        //selling case
        //transaction has completed so k-1
        profit = recur_helper(true,pos+1,arr,n,k-1) + arr[pos];
    }

    return max(profit,skip);
    /*
    Time : O(3^N) //since we have three choices everytime
    Space : O(N) //recursive stack
    */
}
int maximum_profit(int k,int n,int arr[]){
    return recur_helper(true,0,arr,n,k);
}

//memorization
//here we have three changing values so we use 3d dp matrix
int dp[MAX][MAX][2]  ;//pos,kvalue,buy,sell
int recur_helper_2(bool isbuy,int pos,int arr[],int n,int k){
    //base case
    if(pos == n || (isbuy && pos == n-1) || k == 0){
        return 0;
    }
    if(dp[pos][k][isbuy]!=-1){
        //checking value 
        return dp[pos][k][isbuy] ;
    }
    int profit = 0;
    //skipping this transaction
    int skip = recur_helper_2(isbuy,pos+1,arr,n,k);

    if(isbuy){
        //buying case
        profit = recur_helper_2(false,pos+1,arr,n,k)-arr[pos];
    }
    else{
        //selling case
        //transaction has completed so k-1
        profit = recur_helper_2(true,pos+1,arr,n,k-1) + arr[pos];
    }

    return dp[pos][k][isbuy] = max(profit,skip);
    /*
    Time : O(N^2) //since we have three choices everytime
    Space : O(N) //recursive stack + dp matrix
    */
}
int maximum_profit_2(int k,int n,int arr[]){
    memset(dp,-1,sizeof(dp));
    return recur_helper_2(true,0,arr,n,k);
}

//bottom - up 
int maxProfit_1(int k, int n, int arr[]) {
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<=k;i++){
            int maxi = INT_MIN ;
            for(int j = 1;j<n;j++){
                //for finding maximum value
                for(int k = 0 ;k<j;k++){
                    maxi = max(maxi,dp[i-1][k]-arr[k]) ;
                }
                //then updating value
                dp[i][j] = max(dp[i][j-1],maxi+arr[j]);
                //maxprofit = maximum(if no transaction,selling at that day )
            }
        }
        return dp[k][n-1];
        /*
        Time : O(N*k*N)
        Space : O(N*k)
        */
    }
int maxProfit(int k, int n, int arr[]) {
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<=k;i++){
            int maxi = INT_MIN ;
            for(int j = 1;j<n;j++){
                maxi = max(maxi,dp[i-1][j-1]-arr[j-1]);//for finding maximum value
                dp[i][j] = max(dp[i][j-1],maxi+arr[j]);
                //maxprofit = maximum(if no transaction,selling at that day )
            }
        }
        return dp[k][n-1];
        /*
        Time : O(N*k)
        Space : O(N*k)
        */
    }
int main(){
    int arr[] = {10,22,5,75,65,80};
    cout<<maxProfit_1(2,6,arr)<<endl;
    return 0;
}