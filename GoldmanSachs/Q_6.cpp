#include "bits/stdc++.h"
#include <iostream>
using namespace std;
/*
https://leetcode.com/problems/greatest-common-divisor-of-strings/
For two strings s and t, we say "t divides s" if and only if 
s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, 
return the largest string x such that x divides both str1 and str2
*/
//brute force
 bool check(string s1,string s2,string temp){
     //checking for repetation
        int l1 = s1.length()/temp.length();
        int l2 = s2.length()/temp.length();
        string temp1 = "";
        string temp2 = "";
        while(l1){
            temp1 = temp1+temp;
            l1--;
        }
        while(l2){
            temp2 = temp2+temp ;
            l2--;
        }
        return (temp2 == s2 && temp1 == s1);
    }
    
    string gcdOfStrings(string str1, string str2) {
        
        int l1 = str1.length();
        int l2 = str2.length();
        if(l1>l2){
            //just making sure str1 is small
            swap(l1,l2);
            swap(str1,str2);
        }
        string ans = "";
        for(int i=1;i<=l1;i++){
            string temp = str1.substr(0,i);
            string temp2 = str2.substr(0,i);
            if(temp == temp2){
                if(check(str1,str2,temp)){
                    ans =  temp ;
                }
                
            }
            else{
                return "";
            }
        }
        return ans;
        /*
        Time :O(N^2)
        Space:O(1)
        */
    }
 string gcdOfStrings_2(string str1, string str2) {
         int n1 = str1.size();
    int n2 = str2.size();
    if(str1+str2 == str2+str1)//makig sure of strings
    {   
        return str1.substr(0,__gcd(n1,n2));
    }
    return "";

    /*
    Time : O(N)
    space: O(1)
    */
        
    }
int main(){

    cout<<gcdOfStrings("ABABABAB","ABAB")<<endl;

    return 0;
}