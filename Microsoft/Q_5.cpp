#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and 
we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of 
consecutive days just before the given day, for which the price of the stock on the current 
day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
 then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

*/
vector<int> calculateSpan_2(int arr[],int n){
    vector<int> ans ;
    for(int i = 0;i<n;i++){
        int cnt = 1;
        int j = i-1;
        while(j >=0 && arr[j]<=arr[i] ){
            j--;
            cnt++;
        }
        ans.push_back(cnt) ;
    }
    return ans;
    /*
    Time : O(N^2)
    Space :O(1)
    */
}
vector <int> calculateSpan(int arr[], int n){
    //using stack
      vector<int> ans;
      stack <pair<int,int>> st;
      for(int i = 0;i<n;i++){
          if(st.size()==0){
              ans.push_back(-1);
          }
          else if(st.size()>0 && st.top().first > arr[i]){
              ans.push_back(st.top().second) ;
          }
          else if(st.size()>0 && st.top().first<=arr[i]){
              while(st.size()!=0 && st.top().first<=arr[i]){
                  st.pop();
              }
              if(st.size()==0){
                    ans.push_back(-1);
              }
              else if (st.top().first>arr[i]){
                  ans.push_back(st.top().second) ;
              }
          }
          st.push({arr[i],i});
          ans[i] = i-ans[i] ; //for calucating the span
      }
      return ans ;
      /*
      Time : O(N)
      Space : O(N)
      */
       
    }
int main(){
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = calculateSpan(arr,7) ;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}