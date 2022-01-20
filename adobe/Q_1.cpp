#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
subarray sum ,given target

*/

vector<int> subarrayssums_2(int arr[],int n,long long s){
    vector<int> ans ;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            long long sum = 0;
            for(int k = i;k<=j;j++){
                sum = sum + arr[k] ;
            }
            if(sum == s){
                ans.push_back(i+1) ;
                ans.push_back(j+1) ;
                return ans ;
            }
        }
    }
    return {-1};
    /*
    Time : O(N^3)
    Space : O(1)
    */
}
vector<int> subarraysums(int arr[],int n,long long s){
    vector<int> ans ;
    long long sum = 0;
    for(int i = 0;i<n;i++){
        sum = 0;
        for(int j = i;j<n;j++){
            s += arr[j] ;
            if(sum == s){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans ;
            }
        }
    }

    return {-1};
    /*
    Time : O(N^2)
    Space : O(1)
    */
}
vector<int> subarraySum(int arr[], int n, long long s){
        //sliding window
        //variable
        //fixed work sum
        vector<int> ans ;
        int i = 0;
        int j = 0;
        long long sum = 0;
        while(j<n){
            sum = sum + arr[j] ;
            if(sum == s){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans ;
            }
            else if(sum>s){
                while(i<n && sum> s){
                    sum = sum - arr[i] ;
                    i++;
                }
                if(sum == s){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans ;
                    
                }
            }
            
            j++;
        }
        
        return {-1} ;
        /*
        Time : O(N)
        Space : O(1)
        */
        
    }

int main(){
    int arr[] = {1,2,3,7,5,6,7,8} ;
    vector<int> ans  = subarraySum(arr,10,15) ;
    if(ans.size() == 1){
        cout<<-1<<endl ;
    }
    cout<<"Starting Index : "<<ans[0]<<" Ending Index :"<<ans[1]<<endl ;
    return 0;
}