#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
*/
struct compare{
        bool operator()(string a,string b){
            if(a.length()!=b.length())return a.length()>b.length();
            return a>b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,compare>pq;
        int n = nums.size() ;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        return pq.top();
        /*
        Time : O(nlogk)
        Space : O(N)
        */
    }
int main() {
/**/
return 0;
}