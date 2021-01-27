/*
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited 
from left side. */
 

//RECURSIVE
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data = data;
        right=left=NULL;
    }
};

void leftViewHelper(node* root, int level, int* max_level){
    if(root == NULL) return;
    
    if(*max_level<level){
        cout<<root->data<<" ";
        *max_level = level;
    }
    
    leftViewHelper(root->left, level+1, max_level);
    leftViewHelper(root->right, level+1, max_level);
    
}

void leftView(node* root){
    int max_level = 0;
    leftViewHelper(root, 1, &max_level);
}
int main(){
    node* root = new node(4);
    root->left = new node(5);
    root->right = new node(2);
    root->right->left = new node(3);
    root->right->right = new node(1);
    root->right->left->left = new node(6);
    root->right->left->right = new node(7);
    
    leftView(root);
    return 0;
    
}

//OPTIMIZED USING QUEUE

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data = data;
        right=left=NULL;
    }
};



void leftView(node* root){
    if(root == NULL) return;
    
    queue<node*> q;
    q.push(root);
    
    while(q.empty() == false){
        
        int sz = q.size();
        
        for(int i=1; i<=sz; i++){
            node* temp = q.front();
            q.pop();
            
            if(i==1)
            cout<<temp->data<<" ";
            
            if(temp->left!=NULL)
            q.push(temp->left);
            
            if(temp->right)
            q.push(temp->right);
            
        }
    }
    
}
int main(){
    node* root = new node(4);
    root->left = new node(5);
    root->right = new node(2);
    root->right->left = new node(3);
    root->right->right = new node(1);
    root->right->left->left = new node(6);
    root->right->left->right = new node(7);
    
    leftView(root);
    return 0;
    
}


































