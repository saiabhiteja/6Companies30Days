#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/divide-two-integers/
*/
/*
    int divide(int num, int div) {
        int divide(int num, int div) {
        
        bool isnum = false ;
        bool isdiv = false ;
        if(num<0) {
            isnum = true ;
            }
        if(div<0) {
            isdiv = true ;
            
        } 
         if((num == INT_MAX && div==1) ||(num == INT_MIN && div==-1)){
            return INT_MAX;
        }
        if((num == INT_MIN && div == 1) || (num == INT_MAX && div==-1)){
            return INT_MIN;
        }
        int cnt = 0 ;
        num = abs(num) ;
        div = abs(div) ;
        //cout<<num<<endl;
        //cout<<div<<endl;
        while(num>=div){
            num = num-div ;
            //cout<<num<<endl;
            if(cnt+1>INT_MAX){
                if(isdiv^isnum){
                    return INT_MIN;
                }
                else{
                    return INT_MAX ;
                }
            }
            else{
                cnt++;
            }
        }
        
        if(isdiv^isnum){
            return (-cnt);
        }
        return cnt ;
        
        
    }
    
*/
int divide(int dividend, int divisor) {
        
        bool sign = 1 ;
        
        if(dividend<0 ^ divisor<0){
            sign = 0;
        }
        long long divid = abs(dividend);
        long long divis = abs(divisor);
        
        if((dividend == INT_MAX && divisor==1) ||(dividend == INT_MIN && divisor==-1)){
            return INT_MAX;
        }
        if((dividend == INT_MIN && divisor == 1) || (dividend == INT_MAX && divisor==-1)){
            return INT_MIN;
        }
        
    long long quotient = 0;
    long long temp =0;
    
    for(int i = 31;i>=0;--i){
        if((temp + (divis<<i) )<=divid){
            temp = temp + (divis<<i);
            quotient = quotient | (1LL << i);
        }
    }
 
    if(sign){
        return(quotient);
    }
    else{
        return(0-quotient);
    }
        
        
        
    }
int main() {
/**/
return 0;
}