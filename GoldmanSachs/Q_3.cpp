#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having 
product less than a given number k
*/
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long pro = 1;
        //variable
        //fixed work = product
        //count subarrays
        int i = 0;
        int j = 0;
        int ans = 0 ;
        while(j<n){
            pro = pro*a[j] ;
            if(pro<k){
                ans = ans + (j-i+1);
            }
            else{
                while(pro>=k && i<n){
                    pro = pro/a[i];
                    i++;
                }
                if(pro<k){
                    ans = ans+(j-i+1);
                }
            }
            j++;
        }
        return ans;
        /*
        Time: O(N)
        space:O(1)
        */
        
    }
int main(){
    vector<int> a = {1, 9, 2, 8, 6, 4, 3};
    cout<<countSubArrayProductLessThanK(a,7,100)<<endl;
    return 0;
}