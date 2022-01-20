#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#
*/

int dp[1000][1000] ;
    int helper(vector<int>& arr,int fir,int las){
        if(fir>las){
            return 0 ;
        }
        if(fir == las){
            return arr[las];
        }
        if(dp[fir][las]!=-1){
            return dp[fir][las] ;
        }
        int f1 = arr[fir]+min(helper(arr,fir+2,las),helper(arr,fir+1,las-1)) ;
        int f2 = arr[las]+min(helper(arr,fir,las-2),helper(arr,fir+1,las-1));
        return dp[fir][las] = max(f1,f2) ;
        
    }
    int maxCoins(vector<int>& arr ,int n){
	    memset(dp,-1,sizeof(dp)) ;
	    return helper(arr,0,n-1) ;
        /*
        Time : O(N^2)
        Space : O(N)
        */
    }
int main(){
    
    return 0;
}