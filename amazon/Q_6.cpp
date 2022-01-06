#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
Given an array arr[] of size N and an integer K. 
Find the maximum for each and every contiguous subarray of size K

*/
int findmaximum(int arr[],int i,int j){
    int ans = arr[i];
    for(int k = i;k<=j;k++){
        ans = max(ans,arr[k]);
    }
    return ans;
    /*
    Time : O(N)
    Space: O(1)
    */
}
vector<int> finmaximum_in_window(int arr[],int n,int k){
    //sliding window
    int ptr1 =0,ptr2 = 0;
    vector<int> ans ;
    while(ptr1<n){
        if((ptr1 - ptr2+1) == k){
            ans.push_back(findmaximum(arr,ptr2,ptr1));//getting maximum
            ptr2++;
        }

        ptr1++;
    }
    return ans;
    /*
    Time : O(N*N)
    Space : O(1) 
    */
}
 vector <int> max_of_subarrays(int arr[], int n, int k)
    {
        //sliding window
        //fixed
        //finding maxmimum
       int i=0,j=0;
       vector<int> ans;
       deque<int> q; //using deque
       while(j<n){
           while(q.size()!=0 && q.back()<arr[j]){
               //making sure of maximum element
               q.pop_back();
           }
           q.push_back(arr[j]);
           if((j-i+1)<k){
               //window size
               j++;
           }
           else if((j-i+1)==k){
               ans.push_back(q.front());
               if(arr[i]==q.front()){
                   q.pop_front();
               }
               i++;
               j++;
               
           }
       }
       return ans;
       /*
       Time : O(N)
       Space :O(K)
       */
    }
int main(){
    int arr[] = {1 ,2 ,3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = max_of_subarrays(arr,9,3);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}