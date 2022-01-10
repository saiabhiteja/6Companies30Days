#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link:https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
Given a matrix of size r*c. Traverse the matrix in spiral form.
*/
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> result ;
    int right,left,top,bottom ;
    //right pointing on last column
    right = cols-1;
    //bottom pointing on last row
    bottom = rows - 1;
    //both top and left points on first row and first column
    top = 0;
    left = 0 ;
    //dir variable decides the direction of elemnets to print 
    //dir = 0 : path is left to right (top row)
    //dir = 1 : path top to bottom (right col)
    //dir = 2 : path right to left (bottom row)
    //dir = 3 : path bottom to top (left col)
    int dir = 0;

    while(left<=right && top<=bottom ){
        if(dir == 0){
            for(int i = left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++ ;

        }
        else if (dir == 1){
            for(int i =top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            right-- ;

        }
        else if (dir==2){
            for(int i = right;i>=left;i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom--;

        }
        else if (dir == 3){
            for(int i = bottom;i>=top;i--){
                result.push_back(matrix[i][left]);
            }
            left++ ;

        }
        dir = (dir+1)%4 ;
    }
    return result;
    /*
    Time :O(N^2)
    Space :O(1) // O(N^2) if we consider results space
    */
    }
int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}} ;
    vector<int> ans = spirallyTraverse(matrix,4,4);
    for(auto it: ans) {
        cout<<it<<" ";
    }
    return 0;
}