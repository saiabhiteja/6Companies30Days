#include <iostream>
#include "bits/stdc++.h"
using namespace std;
long long squaresInChessBoard(long long N) {
    /*
    https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1
    sol if we have 8*8 chess board we will have 64 1*1 squares , 49 2*2 squares,36 3*3 squares..and so on..
    we can use recursion or loop 
    */
        if(N == 1){
            return 1;
        }
        return (N*N + squaresInChessBoard(N-1));
        /*
        Time: O(N)
        space : O(1)
        */
    }

long long squares_2(long long n){
    /*
    as we can observe that are we are in finding the sum squares till N so we can directly use formula of 
    sum of square 
    */
   return ((n*(n+1)*(2*n+1))/6);
   /*
   Time : O(1)
   space:O(1);
   */
}
int main(){
    cout<<squares_2(8)<<endl;
    cout<<squaresInChessBoard(8)<<endl;
    return 0;
}