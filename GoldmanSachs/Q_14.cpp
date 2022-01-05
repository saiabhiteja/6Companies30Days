#include "bits/stdc++.h"
using namespace std;
/*
https://leetcode.com/problems/minimum-size-subarray-sum/
problem-14
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead
*/
 int minSubArrayLen(int target, vector<int>& nums) {
        //variable size window
        //fixed work sum
        //greater than or equal to
        int i = 0;//previous 
        int j = 0;//current
        int n = nums.size();
        long long sum = 0;
        int ans = INT_MAX ;
        while(j<n){
            sum = sum + nums[j] ;
            if(sum >= target){
                ans = min(ans,j-i+1) ;
                //cout<<ans<<endl;
                while(sum>=target){
                    //check for minimum size
                    ans = min(ans,j-i+1) ;
                    //remove sum
                    sum = sum-nums[i];
                    i++;
                }
            }
            j++;
        }
        if(ans == INT_MAX){//if nothing find then ans = 0
            return 0;
        }
        return ans ;

        /*
        Time ~ O(N);
        space : O(1)
        */
    }
int main(){
    vector<int> nums = {2,3,1,2,4,3} ;
    cout<<minSubArrayLen(7,nums)<<endl;
    return 0;
}