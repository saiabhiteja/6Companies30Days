#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://leetcode.com/problems/rotting-oranges/
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


*/

 int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q; //using queue
        int oranges = 0;//count of oranges

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    oranges++;
                }
                if(grid[i][j] ==2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {0,0,1,-1}; //for boundaries
        int dy[4] = {-1,1,0,0};
        
        
        int mins = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        while(q.size()!=0){
            //BFS
            int si = q.size();
            
            for(int i = 0;i<si;i++){
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for(int j = 0;j<4;j++){
                    int nx = x+dx[j];
                    int ny = y+dy[j];
                    
                    if(nx>=0 && nx<rows && ny>=0 && ny<cols){
                        if(grid[nx][ny] == 1){
                            oranges--;
                            grid[nx][ny] = 2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            
            if(!q.empty()){
                mins++;
            }
            
        }

        if(oranges == 0){//checking wether all oranges are rotten or not
            return mins;
        }
        return -1;

        /*
        Time : O(N^2)
        Space :O(N)
        */
    }
int main(){
    vector<vector<int>> grid = {{0,1,2},{0,1,2},{2,1,1}} ;
    cout<<orangesRotting(grid)<<endl;
    return 0;
}