#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/#
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N

*/
//Function to generate binary numbers from 1 to N using a queue
string binary_number(int num){
    //function to convert given number to binary
    string ans = "";
    while(num){
        if(num&1 == 1){
            ans = '1'+ans;
        }
        else{
            ans = '0'+ans;
        }
        num = num>>1 ;
    }
    return ans;
    /*
    Time:O(log2N)
    Space:O(1)
    */
}
vector<string> generate(int N)
{
	vector<string> ans ;
	for(int i = 1;i<=N;i++){
	   ans.push_back(binary_number(i));
	}
	return ans;
    /*
    Time :O(Nlog2N)
    Space : O(Nlog2N)
    */
}
int main(){
    vector<string> ans = generate(5);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}