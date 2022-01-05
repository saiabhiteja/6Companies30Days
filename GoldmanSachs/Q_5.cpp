#include "bits/stdc++.h"
using namespace std ;
int nthuglynumber(int n){
    /*
    https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
    Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
    The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … 
    shows the first 11 ugly numbers. By convention, 1 is included. 
    Write a program to find Nth Ugly Number

    */
   
   int dp[n];
    dp[0] = 1 ;
    int next_2 = 2,next_3 = 3,next_5 = 5 ;
    int i2 = 0,i3 = 0,i5 = 0;
    for(int i = 1;i<n;i++){
        dp[i] = min(next_2,min(next_3,next_5)) ;//finding minimum element
        if(dp[i] == next_2){
            i2++;
            next_2 = dp[i2]*2 ;
        }
        if(dp[i] == next_3){
            i3++;
            next_3 = dp[i3]*3;
        }
        if(dp[i] == next_5){
            i5++;
            next_5 = dp[i5]*5;
        }

    }
    return dp[n-1];
    /*
    Time:O(N)
    space : O(N)
    */
}
int main(){
    cout<<nthuglynumber(10)<<endl;
    return 0;
}