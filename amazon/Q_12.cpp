#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
Given a positive integer, return its 
corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like
 A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. 
 In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on
*/
string colName (long long int n)
    {
        string ans = "";
        if(n<=26){
            char ch = 'A'+(n-1);
            ans = ans+ch ;
            return (ans) ;
        }
        while(n>0){
            char ch = 'A'+(n-1)%26;
            n = (n-1)/26;
            ans = ch + ans ;
            
        }
        return ans;
        /*
        Time : O(LogN)
        Space : O(1)
        */
 }
 
int main(){
    cout<<colName(67)<<endl;
    return 0;
}