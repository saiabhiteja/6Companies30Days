#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart
*/
int height(int N){
        int cnt = 1 ;
        int temp = 0;
        while(temp+cnt <= N){
            temp+=cnt ;
            cnt++;
        }
        return cnt-1;
        /*
        Time : O(N)
        space : O(1)
        
        */
    }
int height(int N){
        /*
        Using formula n*n+1/2
        */
        return ((-1+sqrt(1+8*N))/2);
        /*
        Time : O(1)
        Space : O(1)
        */
    }
int main() {
/**/
return 0;
}