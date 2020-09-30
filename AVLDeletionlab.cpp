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
        root=NULL;
    }
    int max(int a, int b); 
    int height(node *temp);
    node *rightRotate(node *temp);
    node *leftRotate(node *temp);
    node* insert(node* temp, int key); 
    int getBalance(node *temp);
    node* deleteNode(node* temp, int key);
    node *min(node *temp);
    node *minValueNode(node* temp);  
};
node *AVL:: minValueNode(node* temp)  
{  
    node* current = temp;
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
node * AVL::min(node *temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else if (temp->left == NULL)
        {
            return temp;
        }
        else
        {
            min(temp->left);
        }
    }
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
node* AVL:: deleteNode(node* temp, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (temp == NULL)  
       {
            return temp;
       }
    if ( key < temp->info )  
        {
            temp->left = deleteNode(temp->left, key);
        }
    else if( key > temp->info )  
        {
            temp->right = deleteNode(temp->right, key);
        } 
    else
    {  
        if( (temp->left == NULL) || (temp->right == NULL) )  
        {  
            node *temp1 = temp1->left ?  
                         temp1->left :  
                         temp1->right;  
  
            // No child case  
            if (temp1 == NULL)  
            {  
                temp1 = temp;  
                temp = NULL;  
            }  
            else // One child case  
                {
                    *temp1 = *temp;
                }
        }  
        else
        {  
            node* temp1 = minValueNode(temp->right);  
            temp->info = temp1->info;  
            temp->right = deleteNode(temp->right,temp1->info);  
        }  
    }  
    if (temp == NULL)  
        {
            return temp;
        } 
    temp->height = 1 + max(height(temp->left),height(temp->right));  
    int balance = getBalance(temp);  
    // Left Left Case  
    if (balance > 1 && getBalance(temp->left) >= 0)  
        {
            return rightRotate(temp);
        }
    // Left Right Case  
    if (balance > 1 && getBalance(temp->left) < 0)  
    {  
        temp->left = leftRotate(temp->left);  
            return rightRotate(temp);  
    }
    // Right Right Case  
    if (balance < -1 && getBalance(temp->right) <= 0)  
        {
            return leftRotate(temp);
        } 
    // Right Left Case  
    if (balance < -1 && getBalance(temp->right) > 0)  
    {  
        temp->right = rightRotate(temp->right);  
            return leftRotate(temp);  
    }  
  
    return temp;  
}
int main(void)
{
    AVL l1;
    l1.root = l1.insert(l1.root, 10);  
    l1.root = l1.insert(l1.root, 20);  
    l1.root = l1.insert(l1.root, 30);  
    l1.root = l1.insert(l1.root, 40);  
    l1.root = l1.insert(l1.root, 50);  
    l1.root = l1.insert(l1.root, 25);  
    l1.root=l1.deleteNode(l1.root,30);
    l1.root=l1.deleteNode(l1.root,25);
    return 0;
}