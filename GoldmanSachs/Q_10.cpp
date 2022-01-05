#include "bits/stdc++.h"
#include <iostream>
using namespace std;
vector<int> findmax10(vector<int> arr){
    /*
    using bubble sort algo to find last 10 numbers
    for each loop we get max number so we modify bubble sort and find last 10 numbers
    */
   int flag = 0;
   int n = arr.size();
    for(int i =0;i<9;i++)
    {
        for(int j = 0 ; j<n-1-i ;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j+1],arr[j]);
                flag = 1;
            }
        }
        if(flag == 0){
            break ;
        }
    }
    vector<int> ans ;
    for(int i = n-10;i<n;i++){
        ans.push_back(arr[i]);
    }
    return ans ;
    /*
    Time : O(10*N) = O(N) ;
    space : O(1)
    */
}
vector<int> findmax10_2(vector<int> arr){
    /*
    sort the given array and return last 10 numbers
    */
   sort(arr.begin(),arr.end());
   int n = arr.size();
   vector<int> ans ;
   for(int i = n-10;i<n;i++){
       ans.push_back(arr[i]);
   }
   return ans;
   /*
   Time: O(N*LogN) + O(10) sorting plus pushing
   Space: O(1)
   */
}

vector<int> findmax10_3(vector<int> arr){
    /*
    using min heap to find the 10 maximum numbers 
    */
   priority_queue<int,vector<int>,greater<int>> pq ;//min heap

    for(auto it: arr){
        pq.push(it);

        if(pq.size()>10){
            pq.pop();
        }

    }
    vector<int> ans;
    cout<<pq.size()<<endl;
    while(pq.size()!=0){
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans ;
    /*
    Time : O(N*logk) //pushing operation : O(logn)
    Space : O(N) //using priority_queue
    */
}
int main(){
    vector<int> arr = {1,23,22,12,45,67,39,10,27,99,62,32,75,63,123,898,555,696,357,159,123,456,789,654,987,321};
    vector<int> ans = findmax10(arr);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    sort(arr.begin(),arr.end());
    for(int i = arr.size()-10;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}