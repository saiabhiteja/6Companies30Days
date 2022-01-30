#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
*/
bool winnerOfGame(string str) {
        //using slinding window technique
        int i = 0;
        int j = 0 ;
        int n = str.length();
        if(n<3){
            return false;
        }
        int alice = 0;
        int bob = 0;
        int cnt1 = 0,cnt2 = 0;
        while(j<n){
            if(str[j] == 'A'){
                cnt1++;
            }
            else{
                cnt2++;
            }
            
            if((j-i+1) == 3){
                if(cnt1 == 3){
                    alice++;
                }
                
                if(cnt2 == 3){
                    bob++;
                }
                
                if(str[i] == 'A'){
                    cnt1--;
                }
                else{
                    cnt2--;
                }
                i++;
            }
            j++ ;
        }
        return alice>bob ;
        /*
        Time : O(N)
        Space : O(1)
        */
    }

int main() {
/**/
return 0;
}