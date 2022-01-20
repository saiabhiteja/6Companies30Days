#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/#

*/
int lengthOfLongestAP(int arr[], int n) {
        if(n == 1){
            return 1;
        }
        vector<vector<int>> vec (1001,vector<int>(10001,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = arr[i]-arr[j] ;
                if(vec[j][diff] == 0){
                    vec[i][diff] = 2 ;
                }
                else{
                    vec[i][diff] = 1+vec[j][diff];
                }
                ans = max(ans,vec[i][diff]) ;
            }
        }
        return ans ;
    }
int main(){
    
    return 0;
}