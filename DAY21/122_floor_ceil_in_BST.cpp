int FloorCeil(node* root, int input, int& Floor, int& Ceil){
   while(root){
       if(root->val == input){
           Floor = root->val;
           Ceil = root->val;
           return;
       }
       if(root->val<input){
           Floor = root->val;
           root = root->right;
           
       }
       else
       {
           Ceil = root->val;
           root = root->left;
       }
   }
   return;
}
