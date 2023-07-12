  #include<iostream>
  #include<stack>
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
      cout<<"Enter data :"<<endl;
      int data;
       cin>>data;
      if(data==-1)
      {
          return NULL;
      }

      root=new Node(data);
      cout<<"Enter left data of "<<data<<endl;
      root->left=buildtree(root->left);
      cout<<"Enter right data of "<<data<<endl;
      root->right=buildtree(root->right);
      return root;
  }
  void postorder(Node*root)
  {
      stack<Node*>s1,s2;
      s1.push(root);
      while(!s1.empty())
      {
          root=s1.top();
          s1.pop();
          s2.push(root);
          if(root->left!=NULL)
          {
              s1.push(root->left);

          }
          if(root->right!=NULL)
          {
              s1.push(root->right);
          }

      }
      while(!s2.empty())
      {
          cout<<s2.top()->data<<" ";
          s2.pop();
      }


  }
  int main()
  {
      Node*root=NULL;
      root=buildtree(root);
      postorder(root);
      return 0;
  }


