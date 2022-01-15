
/*

link : https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#

*/
void dfs(int i, int j, vector<vector<int>> &grid,int& count){
       int n = grid.size();
       int m = grid[0].size();
       if(i < 0 || j < 0) return;
       if(i >= n || j >= m) return;
       if(grid[i][j] != 1) return;
       count++;
       grid[i][j]=0;
    dfs(i+1,j,grid,count);
    dfs(i,j+1,grid,count);
    dfs(i-1,j,grid,count);
    dfs(i,j-1,grid,count);
    dfs(i+1,j+1,grid,count);
    dfs(i+1,j-1,grid,count);
    dfs(i-1,j+1,grid,count);
    dfs(i-1,j-1,grid,count);
}
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
         int r = grid.size();
       int c = grid[0].size();
       int ans= 0;
       int count =1;
       for(int i = 0; i < r ; ++i){
           for(int j = 0; j < c; ++j){
               count=0;
               if(grid[i][j] == 1){
                   dfs(i,j,grid,count);
                   ans = max(count, Max);
               }
           }
       }
       return ans;
    }