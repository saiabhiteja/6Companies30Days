#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/
*/
void solve(int open,int close,string op,vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        if(open!=0){
            string op1 = op;
            op1.push_back('(');
            solve(open-1,close,op1,ans);
        }
        if(open<close){
            string op2 = op;
            op2.push_back(')');
            solve(open,close-1,op2,ans);
        }
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string op ;
        solve(n,n,op,ans);
        return ans;
    }
int main(){
    
    return 0;
}