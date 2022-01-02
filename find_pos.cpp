#include "bits/stdc++.h"
using namespace std;
/*
problem -7;
M items are to be delivered in a circle of size N. Find the position where the 
M-th item will be delivered if we start from a given position K. 
Note that items are distributed at adjacent positions starting from K
*/
int findPosition(int N , int M , int K) {
        if(N == 1)
        return 1;
        int pos = M % N;
        return (pos+ K - 1) == N ? (pos + K - 1) : (pos + K - 1) % N;
        /*
        time : O(1)
        space: O(1)
        */
    }
int main(){
    cout<<findPosition(5,16,2)<<endl;
    return 0;
}