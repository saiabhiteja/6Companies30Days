#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link: https://leetcode.com/problems/longest-mountain-in-array/
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

*/
int prefix_count(vector<int> arr,int ind){
    //for getting count of previous vales for given  index ind
    int cnt = 0;
    while(ind>=0 && arr[ind]> arr[ind-1]){
        cnt++;
        ind--;
    }
    return cnt ;
    /*
    Time : O(N)
    Space : O(1)
    */
}
int suffix_count(vector<int> arr,int ind){
    //for getting count of next element values for given index ind
    int cnt = 0;
    while(ind<arr.size() && arr[ind]>arr[ind+1]){
        cnt++;
        ind++;
    }
    return cnt;
    /*
    Time : O(N)
    Space : O(1)
    */

}
int long_mountain(vector<int> arr){
    //function for getting long mountain

    int ans = 0;
    int n = arr.size();
    for(int i = 1;i<n;i++){
        int pre = prefix_count(arr,i);
        int suf = suffix_count(arr,i);
        if(pre && suf && (suf+pre+1)>=3 ){
            ans = max(ans , pre+suf+1);
        }
    }
    return ans;
    /*
    Time : O(N^2)
    Space : O(1)
    */
}

int longestMountain(vector<int>& arr) {
    //using prefix and suffix array
        
        int n = arr.size();
        vector<int> prefix(n,0),suffix(n,0);
        
        //for prefix
        for(int i = 1;i<n;i++){
            if(arr[i-1]<arr[i]){
                prefix[i] = 1+prefix[i-1];
            }
        }
        
        //for suffix
        for(int i = n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                suffix[i] = 1+suffix[i+1] ;
            }
        }
        
        int ans = 0;
        
        //for ans
        for(int i = 0;i<n;i++){
            int temp = prefix[i]+suffix[i]+1 ;
            if(prefix[i] && suffix[i] && temp >= 3 ){
                //update ans
                ans = max(temp,ans);
            }
        }
        
        return ans;
        /*
        Time : O(N)
        Space : O(N)
        */
        
}

int longest_mountain(vector<int> arr){
    //two pointers 
    int n = arr.size();
    int left = 0,right = 0;
    int ans = 0;
    for(int i = 1;i<n-1;i++){
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            left = i-1;
            right = i+1;
            while(left>=0 && arr[left]>arr[left-1]){
                left--;
            }
            while(right<n && arr[right]>arr[right+1]){
                right++;
            }
            int size = right-left+1 ;
            if(size >= 3 ){
                ans = max(ans,size);
            }

        }
    }
    return ans;
    /*
    Time : O(N)
    Space :O(1)
    */
}
int main(){
    vector<int> arr = { 2,1,4,7,3,2,5} ;
    cout<<longestMountain(arr)<<endl;
    cout<<long_mountain(arr)<<endl;
    cout<<longest_mountain(arr)<<endl;
    return 0;
}