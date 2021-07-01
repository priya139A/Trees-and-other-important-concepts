#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
/*Node* newnode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}*/
int findMax(Node* root)
{
    if (root == NULL)
        return INT_MIN;
    int root_val = root->data;
    int lmax = findMax(root->left);
    int rmax = findMax(root->right);
    if (lmax > root_val)
        root_val = lmax;
    if (rmax > root_val)
        root_val = rmax;
    return root_val;
}
int findMin(Node* root)
{
    if (root == NULL)
        return INT_MAX;
    int root_val = root->data;
    int lmin = findMin(root->left);
    int rmin = findMin(root->right);
    if (lmin < root_val)
        root_val = lmin;
    if (rmin < root_val)
        root_val = rmin;
    return root_val;
}
/*
        BinarytreeNode* temp = newNode(arr[i]);
        root = temp;
 
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 2, n);
    }
    return root;
}*/
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void preorder(Node *root){
    if(root!=NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *newroot=NULL;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->right=new Node(9);
    root->right->left->left=new Node(8);
    cout << "Preorder : " ;
    preorder(root);
    cout << endl;
    cout << "Postorder : " ;
    postorder(root);
    cout << endl;
    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    cout << "Maximum element in the tree:" << findMax(root) << endl;
    cout << "Minimum element in the tree:" << findMin(root);
}
