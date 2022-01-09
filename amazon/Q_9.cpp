#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix(mat[][]) the task to check if the current configuration 
is valid or not where a 0 represents an empty block.
Note: Current valid configuration does not ensure validity of the final solved sudoku

*/
bool isvalid(int row,int col,int num,vector<vector<int>>mat){
    //function for checking wether we can place that value or not
    for(int i = 0;i<9;i++){
        if(mat[row][i] == num){
            return false;
        }
        if(mat[i][col] == num){
            return false;
        }
        if(mat[3*(row/3)+i/3][3*(col/3)+i%3] == num){
            return false;
        }
    }
    return true;
}
int isValid(vector<vector<int>> mat){
        vector<vector<int>> dup(9,vector<int>(9,0)) ;

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(mat[i][j] == 0){
                    continue ;
                }
                if(isvalid(i,j,mat[i][j],dup)){
                    dup[i][j] = mat[i][j] ;
                }
                else{
                    return 0;
                }
            }
        }
        return 1;
        /*
        Time : O(N*M*9)
        Space : O(N*M)
        */
        
    }
int isvalid_2(vector<vector<int>> mat){
    //using hashmap 
    bool row[9][9] = {false},col[9][9] = {false},box[9][9] = {false} ;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(mat[i][j] == 0){
                continue ;
            }
            int num = mat[i][j] ;
            int idx = 3*(i/3) +j/3 ;
            if(row[i][num-1] || col[j][num-1] || box[idx][num-1]){
                return 0;
            }
            row[i][num-1] = col[j][num-1] = box[idx][num-1] = true;
        }

    }
    return 1;
    /*
    Time : O(N^2)
    Space : O(N);
    */
}
int main(){
    return 0;
}