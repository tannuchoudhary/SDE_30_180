
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


int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  
  cout<<height(root)<<endl;
}
