/*
link : https://practice.geeksforgeeks.org/problems/alien-dictionary/1/#
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
 Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, 
thus you may return any valid order and output will be 1 if the order of 
string returned by the function is correct else 0 denoting incorrect string returned

*/
void dfs_helper(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs_helper(it,vis,st,adj);
            }
        }
        st.push(node);
    }

   
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k] ;
        
        for(int i = 1;i<n;i++){
            string s1 = dict[i-1];
            string s2 = dict[i];
            int j = 0;
            int l1 = s1.length();
            int l2 = s2.length();
            for(int j=0; j<min(l1,l2); j++){
                if(s1[j] != s2[j]){
                   int u = s1[j] - 'a';
                   int v = s2[j] - 'a';
                   adj[u].push_back(v);
                   break;
                }
            };
        }
        
        vector<int>vis(k,0);
        stack<int> st ;
        for(int i = 0;i<k;i++){
            if(!vis[i]){
                dfs_helper(i,vis,st,adj);
            }
        }
        string ans = "";
        while(st.size()!=0){
            int x = st.top();
            ans+= x+'a';
            st.pop();
        }
        //cout<<ans;
        return ans;
        
        
        
    }