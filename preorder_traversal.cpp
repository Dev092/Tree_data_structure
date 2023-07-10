#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*left;
    Node*right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};
Node*buildtree(Node*root)
{
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root=new Node(data);
    cout<<"Enter left node data of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter right node data of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void preorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node*root=NULL;
    root=buildtree(root);
    cout<<"Inorder traversal of tree is : "<<endl;
    preorder(root);
    return 0;
}
