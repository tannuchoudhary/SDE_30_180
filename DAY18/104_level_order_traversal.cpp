//O(N^2) APPROACH 

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    
    node(int data){
        this->data = data;
        right = left = NULL;
    }
};

int height(node* root){
    if(root == NULL) return 0;
    
    else{
        int l_height = height(root->left);
        int r_height = height(root->right);
        
        int ans = (l_height>r_height? l_height : r_height);
        return ans+1;
    }
}

void print_this_level(node* root, int level){
    if(root == NULL) return;
    
    if(level == 1) cout<<root->data<<" ";
    
    else if(level>1){
        print_this_level(root->left, level-1);
        print_this_level(root->right, level-1);
    }
}

void levelOrder(node* root){
    int h = height(root);
    
    for(int i=1; i<=h; i++){
        print_this_level(root, i);
    }
}

int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  
  levelOrder(root);
}
