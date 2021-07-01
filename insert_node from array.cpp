#include<bits/stdc++.h>
using namespace std;
struct BinarytreeNode{
    int data;
    struct BinarytreeNode *left;
    struct BinarytreeNode *right;
};
BinarytreeNode* newNode(int data)
{
    BinarytreeNode* node = (BinarytreeNode*)malloc(sizeof(BinarytreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
BinarytreeNode* insertLevelOrder(int arr[], BinarytreeNode* root,
                       int i, int n)
{
    if (i < n)
    {
        BinarytreeNode* temp = newNode(arr[i]);
        root = temp;
 
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 2, n);
    }
    return root;
}
void preorder(BinarytreeNode *root){
    if(root!=NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    BinarytreeNode *root=insertLevelOrder(arr,root,0,size);
    preorder(root);
}
