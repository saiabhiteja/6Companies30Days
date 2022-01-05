#include "bits/stdc++.h"
#include <iostream>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/decode-the-string2444/1#
An encoded string (s) is given, the task is to decode it. 
The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]]
*/
string decodedString(string s){
    //using stack
        int n = s.length();
        stack<string> st_s;
        stack<int> st_i ;
        string temp = "";
        int i = 0;
        while(i<n){
            if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i]) && i<n){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                st_i.push(num);
            }
            else if(s[i] == '['){
                st_s.push(temp);
                temp = "";
                i++;
            }
            else if(s[i] == ']'){
                int c = st_i.top();
                st_i.pop();
                string res = st_s.top();
                st_s.pop();
                for(int j = 0;j<c;j++){
                    res = res+temp;
                }
                temp = res;
                i++;
            }
            else{
                temp = temp+s[i];
                i++;
            }
        }
        return temp;
        /*
        TIme: O(N)
        space :O(N)
        */
    }
int main(){
    string s = "3[b2[ca]]";
    cout<<decodedString(s)<<endl;
    return 0;
}