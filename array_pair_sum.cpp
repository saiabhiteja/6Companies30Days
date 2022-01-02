#include "bits/stdc++.h"
using namespace std;
/*
problem-15
Given an array of integers and a number k, 
write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k
*/
bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n&1==1){//odd length
            return 0;
        }
        unordered_map<int,int> mp;
        //store remainders
        for(int i = 0;i<n;i++){
            mp[nums[i]%k]++;
        }
        
        for(int i = 0;i<n;i++){
            int rem = nums[i]%k;
            if(rem == 0){
                if( mp[0] == 0 || mp[0]&1 ){
                    return 0;
                }
            }
            else if(mp.find(k-rem)== mp.end() || mp[rem]!=mp[k-rem]){
                return 0;
            }
            
        }
        return 1;
        /*
        time: O(N)
        space : O(N)
        */
        
    }
int main(){
    vector<int> nums = {9, 5, 7, 3};
    cout<<canPair(nums,6)<<endl;
    return 0;
}