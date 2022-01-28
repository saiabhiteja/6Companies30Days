#include <iostream>
#include "bits/stdc++.h"
using namespace std;
struct node {
    int data;
    struct node *left=nullptr, *right=nullptr;

    node(int x){
        data = x;
    }
};



void level_order(node* root){
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        node* t = q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
}
/*
link : https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

*/
bool isleaf(node* root){
    return (root && !root->left && !root->right) ;
}
int helper(node* root){
    if(!root){
        return 0;
    }
    if(isleaf(root)){
        int temp = root->data ;
        root->data = 0;
        return temp ;
    }
    int left_val = helper(root->left);
    int right_val = helper(root->right) ;

    int temp = root->data ;
    root->data = left_val+right_val ;
    temp +=root->data ;

    return temp ;

}
void toSumTree(node* root){

    if(!root){
        return ;
    }

    helper(root) ;

    /*
    Time : O(N)
    Space : O(H) recursive stack
    */

}
int main(){
    //creating tree;
    node* root = new node(5);
    root->left = new node(10);
    root->right = new node(12);
    root->right->right = new node(20);
    root->left->left = new node(25);
    root->left->right = new node(35);
    root->right->left = new node(40);

    toSumTree(root) ;

    level_order(root);
   

    return 0;
}