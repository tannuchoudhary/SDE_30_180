//Approach - 01
//T.C - O(N^2)

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

void print_this_level(node* root, int level, bool ltr){
    if(root == NULL) return;
    
    if(level == 1) cout<<root->data<<" ";
    
    else if(level>1){
        if(ltr){
        print_this_level(root->left, level-1, ltr);
        print_this_level(root->right, level-1, ltr);
        }
        else{
            print_this_level(root->right, level-1, ltr);
            print_this_level(root->left, level-1, ltr);
        }
    }
}

void printSpiral(node* root){
    int h = height(root);
    
    bool ltr = false;
    for(int i=1; i<=h; i++){
        print_this_level(root, i, ltr);
        ltr = !ltr;
    }
}

int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  
  printSpiral(root);
}

//OPTIMIZE T.C- O(N)

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



void printSpiral(node* root){
   if(root == NULL) return;
   
   stack<node *> s1;
   stack<node *>s2;
   
   s1.push(root);
   
   while(!s1.empty() || !s2.empty()){
       while(!s1.empty()){
           node* current = s1.top();
           s1.pop();
           cout<<current->data<<" ";
           
           if(current->right!=NULL) s2.push(current->right);
           if(current->left!=NULL)  s2.push(current->left);
       }
       
       while(!s2.empty()){
           node* current = s2.top();
           s2.pop();
           cout<<current->data<<" ";
           
           if(current->right!=NULL) s1.push(current->left);
           if(current->left!=NULL)  s1.push(current->right);
       }
   }
}

int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  
  printSpiral(root);
}
