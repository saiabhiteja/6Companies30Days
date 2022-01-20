#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#

*/
vector<string> winner(string arr[],int n)
    {
        map<string,int> mp ;
        int ma = 0;
        for(int i = 0;i<n;i++){
            mp[arr[i]]++;
            ma = max(ma,mp[arr[i]]) ;
        }
        vector<string> ans ;
        for(auto it : mp){
            if(it.second == ma){
                ans.push_back(it.first);
                ans.push_back(to_string(ma)) ;
                return ans ;
            }
        }
        return {};
        
    }
int main(){
    return 0;
}