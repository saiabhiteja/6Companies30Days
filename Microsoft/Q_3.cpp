#include <iostream>
#include "bits/stdc++.h"
#define MAX 10
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise 
direction without using any extra space.
*/
void rotate_matrix_1(int arr[MAX][MAX],int n){
    //using extra space
    //rotation of anticlockwise 90
    int dup[n][n] = {0};
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            dup[n-j-1][i] = arr[i][j] ;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            arr[i][j] = dup[i][j] ;
        }
    }
    /*
    Time : O(N^2)
    Space : O(N^2)
    */
}

void rotate_matrix_2(vector<vector<int>>& arr,int n){
//rotating the matrix anti-clockwise by 90 degrees
/*
find transpose 
then swap accodingly
*/
//for transpose
for(int i = 0;i<n;i++){
    for(int j = 0;j<i;j++){
        swap(arr[i][j],arr[j][i]);
    }
}
int first ,last ;
first = 0;
last = n-1 ;
while(first<last){
    swap(arr[first],arr[last]) ;
    first++;
    last--;

    }
    /*
    Time : O(N^2)
    Space : O(1)
    */
}

int main(){
    vector<vector<int>> arr = {{1,2,3},
                                {4,5,6},
                                {7,8,9}} ;
    rotate_matrix_2(arr,3);
    for(auto it: arr){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}