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
