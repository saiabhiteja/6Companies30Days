#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/
Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. 
no matter how one parenthesize the product, the result will be the same

*/
//using recursion
pair<int,string> mcm_string(int arr[],int i,int j){
    if(i>j){
        return {0,""};
    }
    if(i == j){
        //cout<<i<<endl;
        return {0,""+string(1,'A'+(i-1))};
    }
    int ans = INT_MAX ;
    string str;
    for(int k = i;k<=j-1;k++){
        auto t1 = mcm_string(arr,i,k);
        auto t2 = mcm_string(arr,k+1,j);
        int temp = t1.first + t2.first + arr[i-1]*arr[j]*arr[k];
        if(ans>temp){
            ans = temp;
            str = t1.second + t2.second ;
            //cout<<str<<endl;
        }
    }
    return {ans,"("+str+")"} ;
    /*
    Time : ~O(2^N) //exponential
    Space : O(N) //recursive stack
    */
}
string matrixChainOrder(int A[], int n) {
        return mcm_string(A, 1, n - 1).second;
}
//using memorization
unordered_map<string,pair<int,string>> dp ;
pair<int,string> mcm_string_2(int arr[],int i,int j){
    if(i>j){
        return {0,""};
    }
    if(i == j){
        //cout<<i<<endl;
        return {0,""+string(1,'A'+(i-1))};
    }
    string key = to_string(i)+"#"+to_string(j);
    if(dp.find(key)!=dp.end()){
        return dp[key] ;
    }
    int ans = INT_MAX ;
    string str;
    for(int k = i;k<=j-1;k++){
        auto t1 = mcm_string(arr,i,k);
        auto t2 = mcm_string(arr,k+1,j);
        int temp = t1.first + t2.first + arr[i-1]*arr[j]*arr[k];
        if(ans>temp){
            ans = temp;
            str = t1.second + t2.second ;
            //cout<<str<<endl;
        }
    }
    return dp[key] =  {ans,"("+str+")"} ;
    /*
    Time : O(N^3)
    Space : O(N^2) //dp map
    */
}
string matrixChainOrder_2(int A[], int n) {
        return mcm_string_2(A, 1, n - 1).second;
}

int main(){
    int arr[] = {1,2,3,4,5} ;
    cout<<matrixChainOrder_2(arr,5);
    return 0;
}