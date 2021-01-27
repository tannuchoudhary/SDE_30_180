//RECURSIVE

#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node* left;
   Node* right;
   
   Node(int data){
       this->data = data;
       left=right=NULL;
   }
};

void print_inorder(Node* node){
    if(node == NULL)
    return;
    
    print_inorder(node->left);
    cout<<node->data<<" ";
    print_inorder(node->right);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"INORDER :"<<endl;
    print_inorder(root);
    return 0;
    
}

//ITERATIVE

#include<bits/stdc++.h>
using namespace std;

class node{
   public:
   int data;
   node* left;
   node* right;
   
   node(int data){
       this->data = data;
       right = left = NULL;
   }
};

void inorder(node* root){
    stack<node*> s;
    node* current = root;
    
    while(current!=NULL || s.empty()==false){
        while(current !=NULL){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        cout<<current->data<<" ";
        s.pop();
        current = current->right;
        
    }
    
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left  = new node(4); 
    root->left->right = new node(5); 
    
    inorder(root);
    return 0;
}
