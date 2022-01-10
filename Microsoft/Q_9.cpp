#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX()
that returns the count of the number of subtress having total node’s data sum equal to the value X.

*/
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
bool isleaf(node* root){
    return ((root) && !(root->left) && !(root->right));
}
int solve(node* root,int target ,int& count){
    if(!(root)){
        return 0;
    }
    if(isleaf(root)){
        if(root->data == target){
            count++;
        }
        return root->data ;
    }
    int left = solve(root->left,target,count);
    int right = solve(root->right,target,count);
    if(root->data+left+right == target){
        count++;
    }
    root->data = root->data+left+right ;
    return root->data ;
}
int countSubtreesWithSumX(node* root, int X)
{
	if(root == NULL){
	    return 0;
	}
	int count = 0;
	solve(root,X,count);
	return count;
    /*
    Time : O(N)
    Space : O(H) //recursive stack
    */
}
int main(){
    //creating tree;
    node* root = new node(5);
    root->left = new node(-10);
    root->right = new node(3);
    root->right->right = new node(7);
    root->left->left = new node(9);
    root->left->right = new node(8);
    root->right->left = new node(-4);

    //function
    cout<<countSubtreesWithSumX(root,7)<<endl;


   

    return 0;
}