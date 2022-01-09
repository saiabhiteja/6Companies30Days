#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. 
Match nuts and bolts efficiently.
Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
The elements should follow the following order ! # $ % & * @ ^ ~ .

*/
void matchPairs(char nuts[], char bolts[], int n) {
        //just sort so that all nuts and boults matchs
	    sort(nuts,nuts+n);
	    sort(bolts,bolts+n);
        /*
        Time : O(N*logN)
        Space : O(1)
        */
}
void matchPairs_2(char nuts[], char bolts[], int n) {
	    string order = "!#$%&*@^~." ;
	    int idx = 0;
	    for(int i = 0;i<order.length();i++){
	        for(int j = 0;j<n;j++){
	            if(order[i] == nuts[j]){
	                swap(nuts[j],nuts[idx]);
	                bolts[idx] = nuts[idx];
	                idx++;
	            }
	        }
	    }
        /*
        Time : O(10*N)
        Space : O(1) //consdering string as constant size
        */
	}
int main(){
    char nuts[] = {'^', '&', '%', '@', '#', '*', '$', '~', '!'};
    char bolts[] = {'~', '#', '@', '%', '&', '*', '$' ,'^', '!'};
    matchPairs(nuts,bolts,9);
    for(int i = 0;i<9;i++){
        cout<<nuts[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<9;i++){
        cout<<bolts[i]<<" ";
    }
    return 0;
}