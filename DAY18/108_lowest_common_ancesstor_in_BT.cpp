//Approach-01
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

bool find_path(node* root, vector<int> &path, int n){
    if(root == NULL) return false;
    if(root->data == n) return true;
    path.push_back(root->data);
    if((root->left && find_path(root->left, path, n)) || (root->right && find_path(root->right, path, n)))
    return true;
    
    path.pop_back();
    return false;
}

int find_LCA(node* root, int n1, int n2){
    vector<int>path1;
    vector<int>path2;
    
    if(!find_path(root, path1, n1) || !find_path(root, path2, n2)) return -1;
    
    int i;
    for(i=0; i<path1.size()&&i<path2.size(); i++){
        if(path1[i] != path2[i]) break;
    }
    return path1[i-1];
    
}


int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  int height = 0;
  cout<<find_LCA(root, 4, 5);
  return 0;
}

//Approach-02

