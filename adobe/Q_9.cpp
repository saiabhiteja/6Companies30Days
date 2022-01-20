#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/#
*/

string nextPalin(string N) { 
          int len = N.size()/2;
       
        for(int i=len-1; i>0; i--)
        {
            if(N[i]>N[i-1])
            {
                int index = len-1;
                while(index>=i)
                {
                    if(N[index]>N[i-1])
                    {
                        swap(N[i-1],N[index]);
                        break;
                    }
                    index--;
                }
                if(index!=i-1)
                {
                    reverse(N.begin()+i,N.begin()+len);
                }
                for(int i=0; i<len; i++)
                {
                    N[N.size()-1-i] = N[i];
                }
                return N;
            }
        }
        return "-1";
    
}
int main(){
    
    return 0;
}