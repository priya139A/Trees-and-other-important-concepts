#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
int leftviewfull(Node *root,int level,int *max_value){
    if(root==NULL){
        return 0;
    }
    else
        if(*max_value < level){
            cout << root->data << " ";
            *max_value=level;
        }
        leftviewfull(root->left,level+1,max_value);
        leftviewfull(root->right,level+1,max_value);
}
int leftview(Node *root){
    int max_value=0;
    leftviewfull(root,1,&max_value);
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main(){
    Node *newroot=NULL;
    Node *root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(7);
    root->left->right=new Node(8);
    root->right->left=new Node(12);
    root->right->right=new Node(15);
    root->right->right->left=new Node(14);
    inorder(root);
    cout << endl;
    leftview(root);
    
}
