#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most 
underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. 
He has stats of runs scored by all N players in the previous season and 
he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game

*/
//same question finding maximum in subarray of size k
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
vector<int> max_of_subarrays_2(int arr[],int n,int k){
    //sliding window
    //fixed
    //finding maximum
    priority_queue<pair<int,int>> pq;//max heap
    int i = 0;
    int j = 0;
    vector<int> ans ;
    while(j<n){
        pq.push({arr[j],j});
        if((j-i+1) == k){
            ans.push_back(pq.top().first);
            while(pq.size()!=0){
                if(pq.top().second <=i){
                    pq.pop();
                }
                else{
                    break;
                }
            }
            i++;
        }
        j++;
    }
    return ans;
    /*
    Time : O(N) + O(klogn)
    Space :O(k)
    */
}
int main(){
    int arr[] = {1 ,2 ,3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = max_of_subarrays_2(arr,9,3);
    for(auto it: ans){
        cout<<it<<" " ;
    }
    return 0;
}