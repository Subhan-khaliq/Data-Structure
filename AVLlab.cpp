#include<iostream>
using namespace std;
class node
{
    public:
        node *left;
        node *right;
        int info;
        int height;
    node(int val)
    {
        left=NULL;
        right=NULL;
        info=val;
        height=1;
    }
};
class AVL
{
    public:
        node *root;
    AVL()
    {
        root =NULL;
    }
    int max(int a, int b); 
    int height(node *temp);
    node *rightRotate(node *temp);
    node *leftRotate(node *temp);
    int getBalance(node *temp);
    node* insert(node* temp, int key); 
    void print(node *temp);

};
int AVL::height(node *temp)  
{  
    if (temp==NULL)  
      {  
        return 0;
      }
    else
    {
        return temp->height;
    }
}
int AVL::max(int a, int b)  
{  
    if(a<b)
    {
        return a;
    }
    return b;
}
node * AVL::rightRotate(node *temp)  
{  
    node *x = temp->left;  
    node *y = x->right;  
    x->right = temp;  
    temp->left = y;  
    temp->height = max(height(temp->left),height(temp->right)) + 1;  
    x->height = max(height(x->left),height(x->right)) + 1;  
    return x;  
}
node * AVL::leftRotate(node *temp)  
{  
    node *x = temp->right;  
    node *y = x->left;  
  
    x->left = temp;  
    temp->right = y;  
    temp->height = max(height(temp->left),height(temp->right)) + 1;  
    x->height = max(height(x->left),height(x->right)) + 1;  
    return x;  
}  
int AVL::getBalance(node *temp)  
{  
    if (temp == NULL) 
       {
            return 0;
       }  
    return height(temp->left) - height(temp->right);  
}  
node* AVL::insert(node* temp, int key)  
{  
    if (temp == NULL)  
       { temp =new node(key);
        return temp;
       }
    if (key < temp->info)  
       {
            temp->left = insert(temp->left, key);
       }
    else if (key > temp->info)  
        {
            temp->right = insert(temp->right, key);
        }  
    else 
        {
            return temp;
        }
  
    temp->height = 1 + max(height(temp->left),height(temp->right));  
    int balance = getBalance(temp);  
    // Left Left Case  
    if (balance > 1 && key < temp->left->info)  
        return rightRotate(temp);
    // Right Right Case  
    if (balance < -1 && key > temp->right->info)  
        return leftRotate(temp);  
  
    // Left Right Case  
    if (balance > 1 && key > temp->left->info)  
    {  
        temp->left = leftRotate(temp->left);  
        return rightRotate(temp);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < temp->right->info)  
    {  
        temp->right = rightRotate(temp->right);  
        return leftRotate(temp);  
    }  
  
    return temp;  
} 
void AVL::print(node *temp)
{
    if(temp==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    if(temp!=root)
    {
        cout<<temp->info<<" ";
    }
    else if(temp==root)
    {
        cout<<temp->info<<" ";
    }
    if(temp->left!=NULL)
    {
        print(temp->left);
    }
    if(temp->right!=NULL)
    {
        print(temp->right);
    }
}
int main(void)
{
    AVL l1;
    l1.root=l1.insert(l1.root,11);
    l1.root=l1.insert(l1.root,20);
    l1.root=l1.insert(l1.root,30);
    l1.root=l1.insert(l1.root,5);
    l1.root=l1.insert(l1.root,7);
    l1.root=l1.insert(l1.root,9);
    l1.root=l1.insert(l1.root,10);
    l1.print(l1.root);
    return 0;
}