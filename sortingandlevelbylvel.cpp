#include<iostream>
using namespace std;
int in[10]={98,54,23,11,99,123,4,69,87,55};
int out[10]={0,0,0,0,0,0,0,0,0,0};
int p=-1;
class node
{
    public:
        int data;
        node *left;
        node *rigth;
        node(int x)
        {
            data=x;
            left=NULL;
            rigth=NULL;
        }
};
class BST
{
    public:
        int length;
        node *root;
        node *current;
        BST()
        {
            root=NULL;
            length=0;
        }
        void insert(int val,node *t);
        void In_order(node *temp);
        void Post_order(node *temp);
        void sort(char x);
        void showLevel(node *root, int level);
        int height(node *node);
        void levelbylevel(int x);
};
int BST::height(node *root)
{
   if (root==NULL)
       return 0;
   else
   {
     int lheight = height(root->left);
     int rheight = height(root->rigth);
  
     if (lheight > rheight)
         return(lheight+1);
     else
        return(rheight+1);
   }
}
void BST::showLevel(node *root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout<<root->data<<" ";
    else if (level > 1)
    {
        showLevel(root->left, level-1);
        showLevel(root->rigth, level-1);
    }
}
void BST::In_order(node *temp)
    {
        if (temp == NULL)
        {    
            return;
        }
        In_order(temp->left);
        out[++p]=temp->data;
        In_order(temp->rigth);
    }
void BST::Post_order(node *temp)
    {
        if (temp == NULL)
            return;
        Post_order(temp->rigth);
         out[++p]=temp->data;
        Post_order(temp->left);
    }
void BST::insert(int val,node *t)
{
    
    if(root==NULL)
    {
        root=new node(val);
        return ;
    }
    if(t->data==val)
    {
        cout<<"Number is already in the tree";
        return;
    }
    else if(val<t->data)
    {
        if(t->left==NULL)
        {
            t->left=new node(val);
            return;
        }
        else
        {
            insert(val,t->left);
        }
        
    }
    else if(val > t->data)
    {
        if(t->rigth==NULL)
        {
            t->rigth=new node(val);
            return;
        }
        else
        {
            insert(val,t->rigth);
        }

    }
}
void BST::sort(char x)
{
    if(x=='A')
    {
        In_order(root);
    }
    else if(x=='D')
    {
        Post_order(root);
    }
    else
    {
        cout<<"Please enter A for Assending OR D for Desending .";
    }
    
}
void BST::levelbylevel(int x)
{
    for(int i=1;i<=x;i++)
    {
        showLevel(root,i);
        cout<<endl;
    }
}
int main(void)
{
    BST l1;
    for(int i=0;i<10;i++)
    {
        l1.insert(in[i],l1.root);
    }
   l1.sort('A');
    for(int i=0;i<10;i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<endl;
    l1.levelbylevel(l1.height(l1.root));
    return 0;
}