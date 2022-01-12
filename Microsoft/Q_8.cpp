#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node

*/
//Function to connect nodes at same level.
    //using BFS
    void connect(Node *root)
    {
      if(root == NULL){
          return;
      }
      
      queue<Node*> q;
      q.push(root);
      
      while(q.size()!=0){
          int s = q.size();
          Node* prev =NULL ;
          for(int i = 0;i<s;i++){
              Node* temp = q.front();
              q.pop();
              temp->nextRight = NULL ;
              if(i == 0){
                  prev = temp;
              }
              else{
                  prev->nextRight = temp;
                  prev = temp;
              }
              if(temp->left){
                  q.push(temp->left);
              }
              if(temp->right){
                  q.push(temp->right);
              }
          }
      }
      /*
      Time : O(N)
      Space : O(N)
      */
    }    

    //using DFS
    void connect_2(Node *root)
    {
      if(root == NULL){
          return;
      }

      if(root->left ){
          //check root->right
          if(root->right){ 
            root->left->nextRight = root->right ;
        }
        else if(root->nextRight){
            //checking for nextRight
              if(root->nextRight->left){
                  root->left->nextRight = root->nextRight->left;
              }
              else{
                  root->left->nextRight = root->nextRight->right ;
              }
          }
      }
      if(root->right && root->nextRight){
            if(root->nextRight->left){
               root->right->nextRight = root->nextRight->left ;
            }
            else{
                root->right->nextRight = root->nextRight->right ;
            }
          }

      connect_2(root->left);
      connect_2(root->right);

      /*
      Time : O(N)
      Space : O(N)
      */
