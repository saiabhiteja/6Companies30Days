#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
There are N stairs, and a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, 
the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same
*/
//using recursion
long long recursion(int n){
    if(n<=2){
        return n;
    }
    return 1+recursion(n-2);
    /*
    Time : O(N)
    Space : O(1) without recursive stack
    */
}
//using memorization
unordered_map<int,long long> mp;
long long recursion_2(int n){
    if(n<=2){
        return n;
    }
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    return mp[n] = 1+recursion_2(n-2);
    /*
    Time : O(N)
    Space : O(N) unordered map
    */
}

//dp
long long countWays(int n)
    {
        if(n<=2){
            return n ;
        }
        long long dp[n+1];
        dp[0] = 0;
        dp[1] = 1 ;
        dp[2] = 2 ;
        for(int i = 3;i<=n;i++){
            dp[i] = 1+dp[i-2];
            //cout<<dp[i]<<endl;
        }
        return dp[n];
        /*
        Time : O(N)
        Space : O(N)
        */
    }

//mathematical
long long countWays_2(int n){
    if(n<=2){
        return n;
    }
    return 1+(n/2);
    /*
    Time : O(1)
    Space :O(1)
    */
}
int main(){
    cout<<countWays(5)<<endl;
    return 0;
}