-----------------------------------------------------------------------------------------------------------
//Approach 01
-----------------------------------------------------------------------------------------------------------

void find_pred_suc_BST(node* root, node*&pre, node*&suc, int key){
    
    if(root==NULL) return;
    
    if(root->val == key){
        if(root->left!=NULL){
            node* temp = root->left;
            while(root->right){
                temp = temp->right
            }
            pre = temp;
        }
        
        if(root->right!=NULL){
            node* temp = root->right;
            while(root->left){
                temp = root->left;
            }
            suc = temp;
        }
    }
    if(key<root->val) {
        suc = root;
        find_pred_suc_BST(root->left, pre, suc, key);
    }
    else{
        pre = root;
        find_pred_suc_BST(root->right, pre, suc, key);
        
    }
}
------------------------------------------------------------------------------------------------------------
//Approach 02
------------------------------------------------------------------------------------------------------------




