#include "bits/stdc++.h"
using namespace std;
/*
problem -4 
Given a string, 
Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded 
and returns the encoded string.
*/

string encode(string src)
{     
  //encoding the string
  string ans = "" ;//empty string for storing answer
  int n = src.length();
  int cnt = 0;//for getting starting position
  for(int i = 0;i<n;i++){
      cnt = i;
      char ch = src[i];
      while(i<n && src[i] == ch){
          i++;
      }
      ans = ans+ch+to_string(i-cnt);//i-cnt for frequency
      i--;
  }
  return ans;
  /*
  complexity
  Time: O(N) we touch every element only once
  space: O(1)
  */
} 


int main(){

    cout<<encode("aabaacdde")<<endl;
    
    return 0;
}