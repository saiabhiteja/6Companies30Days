#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/#
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person 
and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. 
At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is 
unable to come up with an optimal looting strategy. He asks for your help to 
find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it

*/
//recursion
int helper(int arr[],int ind){
        if(ind == 0){
            return arr[ind];
        }
        if(ind == 1){
            return max(arr[0],arr[1]);
        }
        return max(arr[ind]+helper(arr,ind-2),helper(arr,ind-1));
    }
//Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n){
    return helper(arr,n-1);
    /*
    Time : O(2^N)
    Space : O(N)
    */
}


//memorization
int helper_2(int arr[],int ind,vector<int>& dp){
        if(ind == 0){
            return arr[ind];
        }
        if(ind == 1){
            return max(arr[0],arr[1]);
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        return dp[ind] = max(arr[ind]+helper_2(arr,ind-2,dp),helper_2(arr,ind-1,dp));
    }
    //Function to find the maximum money the thief can get.
int FindMaxSum_2(int arr[], int n){
    vector<int> dp(n,-1);
    return helper_2(arr,n-1,dp);
    /*
    Time : O(N)
    Space : O(N) + O(N) recursive stack + dp
    */
}

//bottom up
int FindMaxSum_3(int arr[],int n){
    if(n == 1){
        return arr[0] ;
    }
    if(n == 2){
        return max(arr[0],arr[1]) ;
    }
    int dp[n] ;
    dp[0] = arr[0] ;
    dp[1] = max(arr[0],arr[1]) ;
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],arr[i]+dp[i-2]);
    }
    return dp[n-1];

    /*
    Time : O(N)
    Space : O(N)
    */
}

//space optimised
int FindMaxSum_4(int arr[],int n){
    if(n == 1){
        return arr[0] ;
    }
    if(n == 2){
        return max(arr[0],arr[1]) ;
    }
   int prev2 = arr[0] ;
   int prev1 = max(arr[0],arr[1]) ;
    for(int i=2;i<n;i++){
        int curr = max(prev2+arr[i],prev1);
        prev2 = prev1;
        prev1 = curr ;
    }
    return prev1;

    /*
    Time : O(N)
    Space : O(1)
    */
}

int main(){
    int n = 6 ;
    int a[] = {5,5,10,100,10,5} ;
    cout<<FindMaxSum_4(a,n);
    return 0;
}