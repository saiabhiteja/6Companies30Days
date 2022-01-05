#include "bits/stdc++.h"
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/
problem -7;
M items are to be delivered in a circle of size N. Find the position where the 
M-th item will be delivered if we start from a given position K. 
Note that items are distributed at adjacent positions starting from K
*/
int find_pos_2(int n,int m,int k){
    /*
    for finding the position we can simply travel till we reach mth gift pos
    */
   if(n == 1){
       //there is only one person so answer will be only that person
       return 1;
   }
   //n is greater than 1
   m = m-1;//if there is only one gift he himself will get that gift
   while(m){
       if(k<n){
           k++;
       }
       else{
           k = 1 ;
       }
       m--;
   }
   return k ;
   /*
   Time :O(M)
   Space:O(1)
   */
}
int findPosition(int N , int M , int K) {
        if(N == 1)
        return 1;
        /*
        Further optimisation without using while loop
        % operator returns remainder whose value is between [0,N)
        so now we get our answer in one rotation

        */
        int pos = M % N;//finding position 
        return (pos+ K - 1) == N ? (pos + K - 1) : (pos + K - 1) % N;//checking the positon and returning value
        /*
        time : O(1)
        space: O(1)
        */
    }
int main(){
    cout<<findPosition(5,16,2)<<endl;
    cout<<find_pos_2(5,16,2)<<endl;
    return 0;
}