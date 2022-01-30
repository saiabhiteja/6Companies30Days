#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define mod 1000000007
/*
link : https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart
*/
long long power(int N,int R)
    {
       //N = num
       //r = power
       if(N == 0){
           return 0;
       }
       
       if(R == 0){
           return 1 ;
       }
       
       if(R == 1){
           return N%mod ;
       }
       long long pro = (1LL*N*N)%mod ;
       long long res = power(pro,R/2) ;
       if(R%2 == 0){
           return res%mod ;
       }
       else{
           return (N*res)%mod ;
       }
       /*
       Time : O(logN)
       space : O(logN)
       */
        
    }
long long power(int N,int R)
    {
       //N = num
       //r = power
       if(N == 0){
           return 0;
       }
       
       if(R == 0){
           return 1 ;
       }
       
       if(R == 1){
           return N%mod ;
       }
       
       long long res = power(N,R/2) ;
        res = (res*res)%mod ;
       
       if(R%2 == 0){
           return res%mod ;
       }
       else{
           return (N*res)%mod ;
       }
       
        
    }
int main() {
/**/
return 0;
}