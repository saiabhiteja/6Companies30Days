#include "bits/stdc++.h"
#include <iostream>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat
*/

string printMinNumberForPattern(string s){
        // code here 
        stack<int> st ;//using stack
        int n = s.length();
        int num = 1;
        string ans = "";
        for(int i = 0;i<n;i++){
            if(s[i] == 'D'){
                st.push(num++);
            }
            else{
                st.push(num++);
                while(!st.empty()){
                    ans = ans + to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty()){
            ans = ans+to_string(st.top());
            st.pop();
        }
        return ans;
        /*
        Time: O(N)
        Space:O(N)
        */
    }

    string printMinNumberForPattern_2(string s){
        /*
            using constant space        
        */
        string ans = "1";
       
       int n=s.length(), count=2;
       for(int i=0 ; i<n ; i++)
       {
           ans.push_back(count+48);
           count++;
       }
       
       int i=0, j=1, k=0;//temp pointers
       while(k<n)
       {
           if(s[k]=='I')
           {
               reverse(ans.begin()+i, ans.begin()+j);//reversing it
               i=j;
           }
           j++;
           k++;
       }
       
       if(s.back()=='D')//just checking last charcter
           reverse(ans.begin()+i, ans.begin()+j);
           
       return ans;
       /*
       Time : O(N);
       Space : O(1);
       */
    }
int main(){
    cout<<printMinNumberForPattern_2("IIDDD")<<endl;
    return 0;
}