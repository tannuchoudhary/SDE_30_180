
//TC = O(n^2)
//sc = O(1)

#include<bits/stdc++.h>
using namespace std;

struct bst{
   int data;
   bst *left, *right;
   
   bst(int data){
       this->data = data;
       left = right = NULL;
   }
};

void print_inorder(bst* root){
    if(root == NULL)
    return;
    
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    bst *p, *q;
    bst *root = new bst(arr[0]);
    
    for(int i=1; i<n; i++){
        q = new bst(arr[i]);
        p = root;
        
        while(1){
            if(q->data <= p->data){
                if(p->left == NULL) { 
                    p->left = q;
                    break;
                }
                else p = p->left;
            }
            else if(q->data > p->data){
                if(p->right == NULL){
                    p->right = q;
                    break;
                }
                else p = p->right;
            }
        }
    }
    print_inorder(root);
    
}


