#include "bits/stdc++.h"
#include <iostream>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#
Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and
one number 'B' occurs twice in array. Find these two numbers

simple approach
map<int,int> mp
for(int i = 0;i<n;i++){
    mp[i]++;
}
for(int i = 1;i<=N;i++){
    if(mp[i] == 2){
        repeated = i
    }
    else if(mp[i] == 0){
        missing = i ;
    }
}
-----complexity-----
Time : O(N)+O(N)
space : O(N) map

*/
int *findTwoElement(int *arr, int n) {
         int *a =new int[2];
        //using swap sort
        int i=0;
        while(i<n){
            while(arr[i]!=arr[arr[i]-1] && i<n)
            swap(arr[i],arr[arr[i]-1]);
            
            i++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                a[0]=arr[i];
                a[1]=i+1;
            }
        }
        return a;
        /*
        Time: O(N)
        Space:O(1)
        */
    }

int main(){
    int arr[2] = {2,2};
    int *a = findTwoElement(arr,2);
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}