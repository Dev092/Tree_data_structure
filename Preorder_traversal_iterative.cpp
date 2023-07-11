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
  void preorder(Node*root)
  {
       stack<Node*>st;
       Node*curr=root;
       while(true)
       {
           if(curr!=NULL)
           {
               st.push(curr);
               cout<<curr->data<<" ";
               curr=curr->left;
           }
           else{
            if(st.empty()==true)
            {
                break;
            }
            curr=st.top();
            st.pop();
            curr=curr->right;
           }
       }

  }
  int main()
  {
      Node*root=NULL;
      root=buildtree(root);
      preorder(root);
      return 0;
  }

