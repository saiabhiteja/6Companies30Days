#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
*/
long long dp[1001][1001], MOD = 1000000007;
    
    long long solve(int n, int cnt, int k){
        if(n == 0) return 1;
        
       if(dp[n][cnt] != -1) return dp[n][cnt]%MOD; 
        
        if(cnt == k) return dp[n][cnt] = ((21%MOD)*(solve(n-1, 0, k))%MOD)%MOD;
        
        
        return dp[n][cnt] = (((21%MOD)*(solve(n-1, 0, k))%MOD)%MOD + (5*(solve(n-1, cnt+1, k))%MOD)%MOD)%MOD;
    }
    int kvowelwords(int N, int K) {
        // Write Your Code here
        memset(dp,-1,sizeof(dp)) ;
        
        return solve(N,0,K);
        
    }
int main() {
/**/
return 0;
}