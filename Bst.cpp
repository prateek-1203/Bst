#include<bits/stdc++.h>
using namespace std;
class node
{
public:
   int data;
   node *left;
   node *right;
   node(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
   node *insert(int data, node *&root)
   {
      if (root == NULL)
      {
         return (new node(data));
      }
      if (data < root->data)
         root->left = insert(data, root->left);
      if (data > root->data)
         root->right = insert(data, root->right);
      return root;
   }
   void levelordertraversal(node *&root)
   {
      queue<node *> q;
      q.push(root);
      q.push(NULL);
      while (!q.empty())
      {
         node *temp = q.front();
         q.pop();
         if (temp == NULL)
         {
            // purana level complete ho chuka
            cout << endl;
            if (!q.empty())
            {
               // queue still has some child nodes
               q.push(NULL);
            }
         }
         else
         {
            cout << temp->data << " ";
            if (temp->left)
            {
               q.push(temp->left);
            }
            if (temp->right)
            {
               q.push(temp->right);
            }
         }
      }
   }
    node* getmin(node *root)
    {
       while(root->left!=NULL)
       {
          root=root->left;
       }
       return root;
    }
   node* deleteBST(node *root,int key)
   {
      //1.base case
       if(root==NULL)
       return root;
      //2.base case
      if(root->data==key)
      {
         //0 child
         if(root->left==NULL && root->right==NULL)
         {
            delete root;
            return NULL;
         }
         //1 child

         //left child
        else if(root->left!=NULL && root->right==NULL)
          {
             node *temp=root->left;
             delete root;
             return temp;
          }
          //right child
           else if(root->left==NULL && root->right!=NULL)
          {
             node *temp=root->right;
             delete root;
             return temp;
          }

          //2 child
          else if(root->left != NULL && root->right != NULL)
          {
             int min=getmin(root->right)->data;
             root->data=min;
             root->right=deleteBST(root->right,min);
             return root;
          }
      }
      else if(root->data>key)
      {
         root->left=deleteBST(root->left,key);
         return root;
      }
      else if(root->data<key)
      {
         root->right=deleteBST(root->right,key);
         return root;
      }
   }

};
int main()
{
   node *root =NULL;
   int n;
   cout<<"enter number of nodes: ";
   cin>>n;
   cout<<"Enter data for inserting:"<<endl;
   for(int i=0;i<n;i++)
   {
     int data;
     cin>>data;
     root = root->insert(data, root);
   }
   cout<<"BST is:"<<endl;
   root->levelordertraversal(root);
   int key;
   cout<<"Enter data for deletion: ";
   cin>>key;
   root->deleteBST(root,key);
   cout<<"After deletion BST is:"<<endl;
   root->levelordertraversal(root);
   return 0;
}