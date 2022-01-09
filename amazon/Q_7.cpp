#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
Given an input stream of A of n characters consisting only of lower case 
alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. 
If there is no such character then append '#' to the answer.

*/
string FirstNonRepeating(string a){
		    vector<vector<int>>hsh(26,vector<int>(2,0));
		    for(int i = 0;i<26;i++){
		        //hsh[i][0] = 0;
		        hsh[i][1] = INT_MAX ;
		    }
		    //int hsh[26] = {0} ;
		    string ans = "";
		    int n = a.length();
		    for(int i = 0;i<n;i++){
		        hsh[a[i]-'a'][0]++;
		        hsh[a[i]-'a'][1] = i;
		        char ch = '#';
		        int ind = INT_MAX ;
		        for(int j = 0;j<26;j++){
		            if(hsh[j][0] == 1 && hsh[j][1] < ind){
		                ind = hsh[j][1];
		                ch = 'a'+j;
		            }
		        }
		        if(ch == '#'){
		            ans = ans+'#';
		        }
		        else{
		            ans = ans+ch ;
		        }
		    }
		    return ans;
            /*
            Time : O(26*N)
            Space : O(26)
            */
}
string FirstNonRepeating_2(string a){
		    
		    int hsh[26] = {0} ;
		    queue<char>q ;//frist in first out
		    string ans = "";
		    int n = a.length();
		    for(int i = 0;i<n;i++){
		        hsh[a[i] - 'a']++;
		        
		        if(hsh[a[i]-'a'] == 1){
		            q.push(a[i]);
		        }
		        
		        while(q.size()!=0 && hsh[q.front()-'a']!=1){
		            q.pop();
		        }
		        
		        if(q.size() == 0){
		            ans = ans+'#';
		        }
		        else{
		            ans = ans+q.front();
		        }
		        
		    }
		    return ans;
            /*
            Time : O(N)
            Space : O(N)
            */
		}
int main(){
    cout<<FirstNonRepeating("saiabhiteja")<<endl;
    return 0;
}