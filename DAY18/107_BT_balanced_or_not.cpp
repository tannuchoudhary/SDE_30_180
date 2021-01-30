//APPROACH 01
//O(n^2)

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


bool is_balanced(node* root){
    if(root == NULL) return true;
    
    int right_height = height(root->right);
    int left_height = height(root->left);
    
   if(abs(left_height - right_height) <= 1 && is_balanced(root->left) && is_balanced(root->right))
   return true;
   return false;
}


int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  
  if(is_balanced(root)) cout<<"BALANCED"<<endl;
  else cout<<"NOT BALANCED"<<endl;
}


//OPTIMIZED
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


int is_balanced(node* root, int* height){
    if(root == NULL){
        *height = 0;
         return 1;
    }
    
    int lh=0, rh=0;
    int left_balanced = is_balanced(root->left, &lh);
    int right_balanced = is_balanced(root->right, &rh);
    
    *height = max(lh, rh)+1;
    
    if(abs(left_balanced - right_balanced)>=2) return 0;
    else return (left_balanced&right_balanced);
    
   
  
}


int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  int height = 0;
  if(is_balanced(root, &height)) cout<<"BALANCED"<<endl;
  else cout<<"NOT BALANCED"<<endl;
}
