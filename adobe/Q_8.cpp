#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/implement-atoi/1/#

*/
int atoi(string str) {
        int n = str.length() ;
        int ans = 0;
        //remvoing space 
        int i = 0;
        while(i<n && str[i] == ' '){
            i++;
        }
        
        if(i == n){
            return -1;
        }
        
        //checking negative number
        bool isnegative = false;
        if(str[i] == '-'){
            isnegative = true ;
            //removing that - character
            i++;
        }
        //starting number
        for(;i<n;i++){
            if(str[i]>='0' && str[i]<='9'){
                ans = ans*10 + (str[i]-'0') ;
            }
            else{
                return -1;
            }
        }
        //if we get answer
        return isnegative == true ? -1*ans:ans ;
        /*
        Time : O(N)
        Space : O(1)
        */
}
int main(){
    return 0;
}