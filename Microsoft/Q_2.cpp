#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1#
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks

*/

//using dfs
bool dfs_helper(int node,vector<int> adj[],vector<int>&vis,vector<int>&dfs_vis){
        vis[node] = 1;
        dfs_vis[node] = 1 ;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs_helper(it,adj,vis,dfs_vis)){
                    return true;
                }
            }
            else if(dfs_vis[it]){
                return true;
            }
        }
        dfs_vis[node] = 0 ;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[N];
	    for(int i = 0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    
	    vector<int> vis(N,0);
	    vector<int> dfs_vis(N,0) ;
	    for(int i = 0;i<N;i++){
	        if(!vis[i]){
	            if(dfs_helper(i,adj,vis,dfs_vis)){
	                return false;
	            }
	        }
	    }
	    
	   return true;
	}
//using bfs 
//khans algo
bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[N];
	    for(int i = 0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    //indegree
	    vector<int>indegree(N,0) ;
	    for(int i=0;i<N;i++){
	        for(auto it: adj[i]){
	            indegree[it]++ ;
	        }
	    }
	    //queue 
	    queue<int> q ;
	    for(int i = 0;i<N;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    int cnt = 0;
	    while(q.size()!=0){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return (cnt == N);
	}