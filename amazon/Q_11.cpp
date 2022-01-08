#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading 
tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] 
and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data
*/
struct node {
    //tree structre
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
    cout<<endl;
    /*
    Time : O(N)
    Space : O(N)
    */
}

//using BFS

//function to serialize given tree
vector<int> serialize(node *root) 
    {
        //using BFS level order
        vector<int> ans;
        if(root == NULL){
            return ans ;
        }
        queue<node*> q;
        q.push(root);
        while(q.size()!=0){
            node* temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(0);
            }
            else{
                ans.push_back(temp->data);
            }
            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
            
        }
        return ans;
        /*
        Time : O(N)
        Space : O(N)
        */
    }
    
    //Function to deserialize a list and construct the tree.
    node * deSerialize(vector<int> &A)
    {
        //using BFS level order
       if(A.size() == 0){
           return NULL;
       }
       node* root = new node(A[0]);
       queue<node*> q;
       q.push(root);
       int i = 1;
       while(q.size()!=0){
           node* temp = q.front();
           q.pop();
           if(A[i] == 0){
               temp->left = NULL ;
               i++;
           }
           else{
               node* leftnode = new node(A[i]);
               temp->left = leftnode;
               q.push(temp->left);
               i++;
           }
           if(A[i] == 0){
               temp->right = NULL ;
               i++;
           }
           else{
               node* rightnode = new node(A[i]);
               temp->right = rightnode;
               q.push(temp->right);
               i++;
           }
           
           
       }
       return root;
       /*
       Time : O(N)
       Space : O(N)
       */
    }


//using recursion
void helper_serialize(node* root,vector<int>& vec){
    if(!root){
        //root = nullptr
        vec.push_back(0);
        return ;
    }
    //root
    vec.push_back(root->data);
    //left
    helper_serialize(root->left,vec);
    //right
    helper_serialize(root->right,vec);
    /*
    Time : O(N)
    Space : O(1) (without recursive stack consideration)
    */
}
vector<int> serialize_2(node* root){

    vector<int> nodes ;
    helper_serialize(root,nodes);
    return nodes;

    /*
    Time : O(N)
    Space:O(1)
    */

}

node* helper_deSerialize(int& idx,int n,vector<int> arr){
    if(idx>=n){
        return NULL;
    }
    if(arr[idx] == 0 ){
        idx++;
        return NULL;
    }
    node* root = new node(arr[idx++]);
    root->left = helper_deSerialize(idx,n,arr);
    root->right = helper_deSerialize(idx,n,arr);
    return root;
    /*
    Time :O(N)
    Space :O(1) //without recursive stack
    */

}


node* deSerialize_2(vector<int> arr){
    int n = arr.size();
    int idx = 0;
    return helper_deSerialize(idx,n,arr);

    /*
    Time :O(N)
    Space : O(1)
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

    level_order(root);

    vector<int> nodes = serialize_2(root);

    for(auto it : nodes){
        cout<<it<<" ";
    }
    cout<<endl;

    node* root2 = deSerialize_2(nodes);

    level_order(root2);

   

    return 0;
}