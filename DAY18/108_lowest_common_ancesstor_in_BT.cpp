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


int find_LCA(node* root, int n1, int n2){
   if(root==NULL) return 0;
   if(root->data == n1 || root->data == n2) return (root->data);
   
   int left_lca = find_LCA(root->left, n1, n2);
   int rightlca = find_LCA(root->right, n1, n2);
   
   if(left_lca&&rightlca) return(root->data);
   
   return((left_lca!=0) ? left_lca : rightlca);
    
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


//LEETCODE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        return (!left ? right : !right ? left : root);
    }
};



