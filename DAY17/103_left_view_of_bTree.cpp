#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data = data;
        right=left=NULL;
    }
};



void bottomViewhelper(node* root, int level, int hrzntl_dist, map<int, pair<int, int>> &m){
   if(root == NULL) return;
   
   if(m.find(hrzntl_dist) == m.end() || level<m[hrzntl_dist].second){
       m[hrzntl_dist] = {root->data, level};
   }
   
   bottomViewhelper(root->left, level+1, hrzntl_dist-1, m);
   bottomViewhelper(root->right, level+1, hrzntl_dist+1, m);
    
}
void bottomView(node* root){
    map<int, pair<int, int>> m;
    bottomViewhelper(root, 0, 0, m);
    
    for(auto it: m)
    cout<<it.second.first<<" ";
}
int main(){
    node* root = new node(4);
    root->left = new node(5);
    root->right = new node(2);
    root->right->left = new node(3);
    root->right->right = new node(1);
    root->right->left->left = new node(6);
    root->right->left->right = new node(7);
    
    bottomView(root);
    return 0;
    
}


































