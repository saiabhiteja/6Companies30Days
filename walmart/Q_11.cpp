#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
/*
link : https://leetcode.com/problems/maximum-performance-of-a-team/
*/
class Solution {
public:
    static bool cmpare(pair<int,int> p1,pair<int,int> p2){
        if(p1.first == p2.first){
            return p1.second<p2.second ;
        }
        return p1.first>p2.first ;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
       int mod = 1e9+7 ;
        vector<pair<int,int>> vec ;
        for(int i = 0;i<n;i++){
            vec.push_back({eff[i],speed[i]}) ;
        }
        sort(vec.begin(),vec.end(),cmpare);
        priority_queue<int,vector<int>,greater<int>> pq ;
        long long maxi=0, sum=0;
        for(int i = 0;i<n;i++){
            pq.push(vec[i].second);
            sum+=vec[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            maxi=max(maxi, sum*vec[i].first);

        }
        return maxi%mod ;
        /*
        Time : O(NlogN)
        Space : O(N)
        */
    }
};
int main() {
/**/
return 0;
}