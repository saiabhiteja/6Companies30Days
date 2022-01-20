#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#
*/
vector<int> leaders(int a[], int n){
        vector<int> ans ;
        priority_queue<int> pq ;
        ans.push_back(a[n-1]) ;
        pq.push(a[n-1]) ;
        for(int i = n-2;i>=0;i--){
            if(pq.top()<=a[i]){
                ans.push_back(a[i]);
            }
            pq.push(a[i]) ;
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;

        /*
        Time : O(N*logn)
        Space : O(N) 
        //gives tle
        */
        
}

vector<int> leaders_2(int a[], int n){
        vector<int> ans ;
        ans.push_back(a[n-1]) ;
        for(int i = n-2;i>=0;i--){
            if(ans[ans.size()-1]<=a[i]){
                ans.push_back(a[i]);
            }
           
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;
        /*
        Time : O(N)
        Space : O(N)
        */
        
    }
int main(){
    return 0;
}