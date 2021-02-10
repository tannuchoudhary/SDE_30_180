//using inorder traversal

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       TreeNode *res =  kthsml(root, k);
       return res->val;
    }
    
   TreeNode* kthsml(TreeNode* root, int& k){
        if(root == NULL) return NULL;
        TreeNode* left = kthsml(root->left, k);
        if(left!=NULL) return left;
        k--;
        if(k==0) return root;
        return kthsml(root->right, k);
    }
};
