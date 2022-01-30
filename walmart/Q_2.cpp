#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/stone-game/
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
    //for finding scores 
	    memset(dp,-1,sizeof(dp)) ;
	    return helper(arr,0,n-1) ;
}

 bool stoneGame(vector<int>& piles) {

    //accumulate 
     int sum = accumulate(piles.begin(),piles.end(),0);
     int alice_score = maxCoins(piles,piles.size());
     int bob_score = sum-alice_score ;
     return (alice_score>bob_score);
     /*
     Time : O(N^2)
     Space : O(N)
     */
        
}

bool stonegame(vector<int>& piles){
    //here we optimise the game so that alice will wine the game so if they ask wether alice will or not 
    //we return true
    return true;
}
int main() {
/**/
return 0;
}