#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number

*/
//extending two pointer techinque
vector<vector<int> > fourSum(vector<int> &arr, int target) {
       vector<vector<int>> ans;
       set<vector<int>> temp;
       //sort
       sort(arr.begin(),arr.end());
       int n = arr.size();
       for(int i = n-1;i>=3 ;i--){
           for(int j = i-1;j>=2;j--){
               int k = j-1;
               int l = 0;
               int tar = target-arr[i]-arr[j] ;
               while(l<k){
                   int s = arr[l]+arr[k] ;
                   //cout<<s<<" "<<tar<<endl;
                   
                   if(s == tar){
                        //cout<<"tar";
                       temp.insert({arr[l],arr[k],arr[j],arr[i]});
                       l++;
                       k--;
                       
                   }
                   else if(s<tar){
                       //cout<<"tar-l";
                       l++;
                   }
                   else{
                       // cout<<"tar-l";
                       k--;
                   }
               }
           }
       }
       for(auto it: temp){
           ans.push_back(it);
       }
       return ans;
    }
int main(){
    vector<int> arr ={0,0,2,1,1} ;
    vector<vector<int>> ans = fourSum(arr,3);
    for(auto it: ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<"#"<<" ";
    }
    return 0;
}