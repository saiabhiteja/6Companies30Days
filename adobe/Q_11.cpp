#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1#
*/
string amendSentence (string s)
    {
        string ans = "";
        int len = s.length() ;
        for(int i = 0;i<len;i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = tolower(s[i]) ;
                if(i!=0){
                    ans.push_back(' ');
                }
            }
            ans.push_back(s[i]) ;
        }
        return ans ;
    }
int main(){
    
    return 0;
}