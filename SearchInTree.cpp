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
int SearchInTree(Node *root,int key){
    int temp;
    if(root==NULL)
        return 0;
    else if(root!=NULL){
        if(root->data==key){
            return 1;
        }
        else{
            temp=SearchInTree(root->left,key);
            if(temp!=0)
                return temp;
            else 
                return SearchInTree(root->right,key);
        }
    }
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout <<  root->data << " ";
        inorder(root->right);
    }
}
int main(){
  Node *newroot=NULL;
  Node *root=new Node(13);
  root->left=new Node(12);
  root->right=new Node(10);
  root->left->left=new Node(4);
  root->left->right=new Node(19);
  root->right->left=new Node(16);
  root->right->right=new Node(9);
  inorder(root);
  cout << endl;
  int t,key;
  cin >>t;
  for(int i=0;i<t;i++){
    cin >> key;
    int temp=SearchInTree(root,key);
    if(temp == 0){
        cout << "NOT FOUND" << endl;
    }
    else
        cout << "FOUND" << endl;
        
    }
}
