#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
*/
 vector<vector<long long>> dp;

    long long numOfWays(long long n, int x) {
        int num = pow(n, 1.0 / x);
        dp.resize(n + 1, vector<long long>(num + 1, -1));
        return helper(n, x, num);
    }
    
    long long helper(int n, int x, int curr) {
        if(n == 0) 
        return 1;
        else if(curr == 0) 
        return 0;
        long long &ans = dp[n][curr];
        if(ans != -1) 
        return ans;
        long long power = pow(curr, x);
        return ans = (n - power >= 0 ? helper(n - power, x, curr - 1): 0) + helper(n, x, curr - 1);
    }
int main() {
/**/
return 0;
}