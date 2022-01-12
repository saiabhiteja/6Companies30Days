#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
Given a keypad as shown in the diagram, and an 
N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers
*/
void helper(vector<string> keypd,vector<string>&ans,int i,int n,int a[],string temp){
        //base case
        if(i == n){
            ans.push_back(temp);
            return;
        }
        string curr = keypd[a[i]] ;
        for(int j = 0;j<curr.length();j++){
            helper(keypd,ans,i+1,n,a,temp+curr[j]);
        }
    }
//Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> keypd = {"#","#","abc","def","ghi","jkl","mno","pqrs","tuv",
                                "wxyz","#"};
                             
        vector<string> ans ;
        helper(keypd,ans,0,N,a,"");
        return ans;
        /*
        Time : O(N*4^N)
        Space :O(N)
        */
        
    }
int main(){
    //array
    int arr[] = {2,3,9} ;
    vector<string> ans = possibleWords(arr,3);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}