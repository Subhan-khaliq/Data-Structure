#include<iostream>
using namespace std;
class node
{
    public:
        node *left;
        node *right;
        int data;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
class CBT
{
    public:
        node *root;
        node *temp;
    CBT()
    {
        root=NULL;
        temp=NULL;
    }
    node* insert(node* r,node* t);
    int height(node *r);
    int bal(node *r);          
    bool check(node *r);  
    void accept(int t);
    void showLevel(node *root, int level);
};
int CBT :: bal(node *r)
{
        if(r == NULL)
            return 0;
        int lheight = height(r->left)+1;
        int rheight = height(r->right)+1;

        return (lheight - rheight);
}
int CBT :: height(node *r)
{
    if(r == NULL)
        return 0;
    else
    {
        int lheight = height(r->left)+1;
        int rheight = height(r->right)+1;
        if(lheight > rheight)
        {
            return lheight;
        }
        return rheight;
    }
}
void CBT::showLevel(node *root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout<<root->data<<" ";
    else if (level > 1)
    {
        showLevel(root->left, level-1);
        showLevel(root->right, level-1);
    }
}
bool CBT :: check(node *r)
{
    
    if(r == NULL)
        return false;
    bool x = check(r->left);
        if(bal(r))
            return true;
    bool y = check(r->right);

    return x||y; 
}
void CBT :: accept(int t)
{
    int x;

    for(int i=0;i<t;i++)
    {
         cout<<"\nEnter the element : ";
         cin>>x;
        temp = new node(x);
        root = insert(root,temp);
    }
}
 node* CBT :: insert(node* r,node* t)
{
    
    if(r == NULL)
        return t;
    else if(bal(r)==0 && check(r->right)) 
        r->right = insert(r->right,t);
    else if(bal(r)==0)            
        r->left = insert(r->left,t);
    else if(bal(r)==1 && check(r->left))
        r->left = insert(r->left,t);
    else if(bal(r)==1)
        r->right = insert(r->right,t);

    return r;
}
int main(void)
{
        CBT c;
        int ch,t;
    do
    {
        cout<<"\n\n\t| Complete Binary Tree |\n";
        cout<<"\n1.Create";
        cout<<"\n2.Insert";
        cout<<"\n3.Exit";
        cout<<"\n>>";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\nEnter the total number of elements : ";
                cin>>t;
                c.accept(t);
                break;
            case 2:
                c.accept(1);
                break;
            case 3:
                cout<<"\n\t**** EXIT ****\n";
                break;
            default:
                cout<<"\n\t**** Invalid Choice ****\n";
                break;
        }
    }while(ch != 4);
    for(int i=1;i<=c.height(c.root);i++)
    {
        c.showLevel(c.root,i);
        cout<<endl;
    }
    return 0;
}