#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/path-with-maximum-probability/
*/
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        //constructing graph
        vector<pair<int,double>> adj[n] ;
        for(int i = 0;i<edges.size();i++){
            //undirected graph
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});
        }
        
        
        //priority queue
        priority_queue<pair<double,int>> pq ;
        vector<double> prob (n,0);
        prob[start] = 1 ;
        pq.push({1,start});
        
        while(pq.size()!=0){
            
            auto t = pq.top() ;
            pq.pop();
            double prev_p = t.first ;
            int node = t.second ;
            
            for(auto it : adj[node]){
                
                int ad = it.first ;
                double curr_p = it.second ;
                
                if(prob[ad]<prev_p*curr_p){
                    prob[ad] = prev_p*curr_p ;
                    pq.push({prob[ad],ad});
                }
                
            }
        }
        return prob[end];
        /*
        Time : O(N*logN)
        Space : O(N)
        */
        
    }
int main() {
/**/
return 0;
}