//approach-01

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


int diameter(node* root){
    if(root == NULL) return 0;
    
    int right_height = height(root->right);
    int left_height = height(root->left);
    
    int right_subtree_diameter = diameter(root->right);
    int left_subtree_diameter = diameter(root->left);
    
    return max(right_height+left_height+1, max(right_subtree_diameter, left_subtree_diameter));
}


int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  
  cout<<diameter(root)<<endl;
}


//O(N) approach (optimized)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
    calc_diameter(root, diameter);
    return diameter;
    }
    
    int calc_diameter(TreeNode* root, int &diameter){
    if(root==NULL) return 0;
    
    int ld = calc_diameter(root->left, diameter);
    int rd = calc_diameter(root->right, diameter);
    
    diameter = max(diameter, ld+rd);
    return max(ld, rd)+1;
}
};
