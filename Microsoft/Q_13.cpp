/*
link : https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
Given a Graph of V vertices and E edges and another edge(c - d), 
the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph

*/

bool dfs_helper(int start,int end,vector<int> adj[],vector<int>&visited){
        if(start == end){
            return true ;
        }
        visited[start] = 1;
        for(auto it: adj[start]){
            if(!visited[it]){
                if(dfs_helper(it,end,adj,visited)){
                    return true ;
                }
            }
        }
        return false ;
    }

    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> new_adj[V] ;
        for(int i = 0;i<V;i++){
            for(auto it: new_adj[i]){
                if((i == c && it == d) || (i==d && it == c)) continue;
                new_adj[i].push_back(it) ;
            }
        }
        vector<int> visited(V,0) ;
        
        return !(dfs_helper(c,d,new_adj,visited)) ;
    }