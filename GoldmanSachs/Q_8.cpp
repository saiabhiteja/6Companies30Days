#include "bits/stdc++.h"
#include <iostream>
#define mod 1000000007
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

*/
//recursive function
int recursive(int ind,int n,string s){

    int ans = 0;
    //base conditions
    if(ind>=n){
        return 1;
    }

    if((s[ind]-'0') == 0){
        //if 0 return 0
        return 0;
    }

    //single number case
    ans += (recursive(ind+1,n,s))%mod;

    //if double digit is possible then calling that function
    if(stoi(s.substr(ind,2))>=10 && stoi(s.substr(ind,2))<=26 && (ind+2)<=n){
        ans+=(recursive(ind+2,n,s))%mod ;
    }

    return ans%mod ;

}

//memorization
unordered_map<int,int> mp;
int recursive_2(int ind,int n,string s){
     int ans = 0;
    //base conditions
    if(ind>=n){
        return 1;
    }

    if((s[ind]-'0') == 0){
        //if 0 return 0
        return 0;
    }

    //before calling just check map
    if(mp.find(n-ind)!=mp.end()){
        return mp[n-ind];
    }

    //single number case
    ans += (recursive(ind+1,n,s))%mod;

    //if double digit is possible then calling that function
    if(stoi(s.substr(ind,2))>=10 && stoi(s.substr(ind,2))<=26 && (ind+2)<=n){
        ans+=(recursive(ind+2,n,s))%mod ;
    }

    return mp[n-ind] = ans%mod ;

}
//bottom up
int recursive_3(string s){
    int n=s.length();
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
   
    if(n==1 && s[0]!='0')
    return 1;
    if(s[0]=='0')
    return 0;
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        
        if(s[i-1]>'0')
        dp[i] = dp[i-1];
        
        if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<'7')
        dp[i] = (dp[i]+dp[i-2])%mod;
    }
    return dp[n];
    /*
    Time : O(N)
    Space : O(N)
    */
}

int main(){
    cout<<recursive_3("123")<<endl;
    return 0;
}