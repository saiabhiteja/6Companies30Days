#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/burning-tree/1/#
Given a binary tree and a node called target. Find the minimum time required to 
burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. 
That is its left child, right child, and parent

*/

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL ;
    }

};

void level_order(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()!=0){
        Node* t = q.front();
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

void parentpointers(Node* root,map<Node*,Node*>& mp){
    //function for creating parent pointers using BFS
        queue<Node*>q;
        q.push(root);
        mp[root] = NULL;
        while(q.size()!=0){
            Node* temp = q.front();
            q.pop();
            if(temp->left){
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right] = temp;
                q.push(temp->right);
            }
            
        }
        /*
        Time : O(N) 
        Space : O(N) queue
        */
    }
    Node* findpointer(Node* root,int target){
        //function for finding the pointer with particular data using BFS
        queue<Node*> q;
        q.push(root);
        while(q.size()!=0){
            Node* temp = q.front();
            q.pop();
            if(temp->data == target){
                return temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            /*
            Time : O(N)
            Space : O(N) //same as Bfs
            */
            
        }
       return NULL ; 
    }
    int minTime(Node* root, int target) 
    {
        //function for finding minimum time
        if(root == NULL){
            return 0;
        }
        Node* element = findpointer(root,target);
        map<Node*,Node*> mp;
        parentpointers(root,mp);
        if(element == NULL){//if element is not present in tree
            return 0;
        }
        map<Node*,bool>visited;//for maintaing visited elements
        queue<Node*> q;
        q.push(element);
        visited[element] = 1;
        int time = 0;
        //BFS
        while(q.size()!=0){
            int s = q.size();
             time++;
            for(int i = 0;i<s;i++){
                Node* temp = q.front();
                q.pop();
                visited[temp] = 1;
                if(mp[temp] && !(visited[mp[temp]])){//checking for parent
                    q.push(mp[temp]);
                }
                if(temp->left && !(visited[temp->left])){//checking for left
                    q.push(temp->left);
                }
                if(temp->right && !(visited[temp->right])){//checking for right
                    q.push(temp->right);
                }
            }
           
        }
        
        return time-1 ;//returning time
        /*
        Time : O(N)
        Space : O(N) + O(N)+O(N) visited,queue,parent pointers
        */
        
    }
int main(){
    //creating tree;
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(12);
    root->right->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(35);
    root->right->left = new Node(40);
    //level order
    //level_order(root);

    //ans
    cout<<minTime(root,40)<<endl;
    return 0;
}