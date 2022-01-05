#include "bits/stdc++.h"
#include <iostream>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
Given an array of strings, return all groups of strings that are anagrams. 
The groups must be created in order of their appearance in the original array.
 Look at the sample case for clarification
*/
vector<vector<string> > Anagrams(vector<string>& arr) {
        /*
        having same characters in both strings
        */
        vector<vector<string>> ans ;
        unordered_map<string,vector<string>> mp;//for storing same anagrams
        for(int i = 0;i<arr.size();i++){
            string temp = arr[i];
            sort(temp.begin(),temp.end()); //sorting so that all anagrams become same
            mp[temp].push_back(arr[i]);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
        /*
        Time : O(N)
        Space : O(N)
        */
}

int main(){
    vector<string> arr = {"act","god","cat","dog","tac"};
    vector<vector<string>> ans = Anagrams(arr) ;
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl ;

    }
    return 0;
}