/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

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
 
 ------------------------------------------------------------------------------------------------------------
 -------------------------------------------------------------------------------------------------------------
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return createTree(0, 0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* createTree(int preI, int inI, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preI>=preorder.size() || inI>inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preI]);
        //if(inI==inEnd) return root;
        int currentInI=0;
        for(int i=inI; i<=inEnd; i++){
            if(inorder[i] == root->val)
                currentInI = i;
        }
        
        root->left = createTree(preI+1, inI, currentInI-1, preorder, inorder);
        root->right = createTree(preI+currentInI-inI+1, currentInI+1, inEnd, preorder, inorder);
        return root;
    }
};


----------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------

 //OPTIMIZED 
 
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        if(preorder.size()>0)
        for(int i=0; i<=(inorder.size()-1); i++)
            m[inorder[i]] = i;
        return createTree(0, 0, inorder.size()-1, preorder, inorder, m);
    }
    
    TreeNode* createTree(int preI, int inI, int inEnd, vector<int>& preorder, vector<int>& inorder, map<int, int>& m){
        if(preI>=preorder.size() || inI>inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preI]);
        //if(inI==inEnd) return root;
        int currentInI=0;
        /*for(int i=inI; i<=inEnd; i++){
            if(inorder[i] == root->val)
                currentInI = i;
        }*/
        currentInI = m[preorder[preI]];
        
        root->left = createTree(preI+1, inI, currentInI-1, preorder, inorder, m);
        root->right = createTree(preI+currentInI-inI+1, currentInI+1, inEnd, preorder, inorder, m);
        return root;
    }
};
