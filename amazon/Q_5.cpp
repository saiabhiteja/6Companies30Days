#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
link : https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a 
query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p 
of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as 
p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".
*/
//using trie
struct node{
    node* links[26];
    int countprefix = 0;
    vector<int> prefix_index ;
    
    node(){
        for(int i = 0;i<26;i++){
            links[i] = nullptr;
        }
    }

    bool iscontains(char ch){
        //checking wether the charcter is already there are not
        return (links[ch-'a'] != NULL) ;

    }

    void put(char ch,node* Node){
        links[ch-'a'] = Node ;
    }

    node* get(char ch){
        //for getting particular link 
        return links[ch-'a'];
    }

    node* get_link(int i){
        return links[i];
    }
    
   
    void increaseprefix(){
        countprefix++;
    }
   
    void decreaseprefix(){
        countprefix-- ;
    }
    int getprefix(){
        return countprefix;
    }
};

class trie{
    private:
    node* root ;
    public:
    trie(){
        root = new node();
    }

    void insert(string s,int ind){
        node* temp = root ;
        for(int i = 0;i<s.size();i++){
            if(!temp->iscontains(s[i])){
                temp->put(s[i],new node());
            }
            
            temp = temp->get(s[i]);
            temp->increaseprefix();
            temp->prefix_index.push_back(ind);
        }
      /*
      Time : O(len(S))
      */
    }
    
    vector<string> get_strings(string s,string con[]){
        //for getting all strings with particular prefix
        node* temp = root;
        vector<string> ans ;
        set<string> se;
        for(int i = 0;i<s.length();i++){
            if(!temp->get(s[i])){
                return {"0"};//failed case
            }
            temp = temp->get(s[i]);
        }

        vector<int> indexes = temp->prefix_index ;
        for(int i = 0;i<indexes.size();i++){
            //set because to remove duplicates
            se.insert(con[indexes[i]]);
        }
        for(auto it:se){
            ans.push_back(it);
        }
        return ans;
        /*
        Time : O(len(s) + nlogn )//set insertion + prefix search
        */
        
    }

};

vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie t;
        //sort(contact,contact+n);
        for(int i = 0;i<n;i++){
            t.insert(contact[i],i);
        }
        vector<vector<string>> ans;
        string temp;
        for(int i = 0;i<s.length();i++){
            temp = temp + s[i];
            vector<string> t1 = t.get_strings(temp,contact);
            ans.push_back(t1);
        }
        return ans;
        /*
        Time : O(N*len(s)*len(prefix))
        */
    }
int main(){
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"} ;
    string s = "geeks" ;
    vector<vector<string>> ans = displayContacts(3,contact,s);
    for(auto it: ans){
        for(auto i : it){
            cout<<i<<" ";
        }
    }
    
    return 0;
}
