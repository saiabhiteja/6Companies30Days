#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/guess-number-higher-or-lower-ii/
*/
vector<vector<int>> dp (201, vector<int>(201,-1))  ;
int helper(int start, int end) {
    //mcm variation
        if (start >= end)
         return 0;

        if (dp[start][end] != INT_MAX) 
        return dp[start][end];
        
        int res = INT_MAX;
        
        for (int i = start; i <= end; i++) {
            int temp = i;
            temp += max(helper(start, i - 1), helper(i + 1, end));
            res = min(res, temp);
        }
        
        
        
        return dp[start][end] = res;
    }

int getMoneyAmount(int n) {
        
        return helper(1, n);
        /*
        Time : O(N^3)
        Space : O(N^2)
        */
    }
int main() {
/**/
return 0;
}