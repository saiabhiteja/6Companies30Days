#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.
*/
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

 // } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        if(!head) return;
        Node* temp = head;
        Node* prev = NULL ;//just keeping previous element
        
        while(temp){
            //skipping m nodes
            for(int i = 1;(i<=m && temp);i++){
                prev = temp;
                temp = temp->next ;
            }
            //deleting n nodes
            for(int i = 1;(i<=n && temp);i++){
                prev->next = temp->next;
                temp = temp->next ;
            }
        }
       /*
       Time : O(N)
       Space : O(1)
       */ 
        
    }
};



// { Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
  // } Driver Code Ends
