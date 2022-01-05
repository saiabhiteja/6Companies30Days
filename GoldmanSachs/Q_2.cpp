#include "bits/stdc++.h"
using namespace std;
/*
problem -2
https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
Given two rectangles, find if the given two rectangles overlap or not. 
A rectangle is denoted by providing the x and y coordinates of two points: 
the left top corner and the right bottom corner of the rectangle. 
Two rectangles sharing a side are considered overlapping. 
(L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).

Note: It may be assumed that the rectangles are parallel to the coordinate axis.
two rectangles in plane

cases:
1.both lies side by side (right-left)
2.both lies above below(top-down)
3.both collide

*/
int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // 4cases 
        //divide it into two cases top and left
        //because if it is right to rec1 then it is left to rec2..same with top and down
        if(L1[0]>R2[0] || R1[0]<L2[0]){
            //left-right
            return false;
        }
        if(L1[1]<R2[1]|| R1[1]>L2[1]){
            //top-down
            return false;
        }
        return true;
        /*
        time : O(1)
        space : O(1)
        */
    }
int main(){
    int l1[] = {0,10} ;
    int r1[] = {10,0};
    int l2[] = {5,5};
    int r2[] = {15,0} ;
    cout<<doOverlap(l1,r1,l2,r2)<<endl;
    return 0;
}