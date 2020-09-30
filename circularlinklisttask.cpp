#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
class list
{
    private:
        int length;
        node *head;
    public:
    list()
    {
        length=0;
        head=NULL;
    }
    void insert(int val,int pos);
    void del(int pos);
    void Josephus();
    void print();
};
void list::Josephus()
{
    node *temp;
    
    int count;
    int count1;
    temp=head;
    while(length!=1)
    {
        node *temp1;
        temp1=temp;
        count=1;
        while(count<3)
        {
            temp=temp->next;
            count++;
        }
        count1=1;
        while(count1<4)
        {
            temp1=temp1->next;
            count1++;
        }
        temp->next=temp1->next;
        temp1->next=NULL;
        delete temp1;
        temp=temp->next;
        length--;
    }
    head=temp;
    head->next=head;
}
void list::del(int pos)
{
    node *temp;
    node *temp1;
    int count=1;
    temp=head;
    if(pos==1)
    {
        head=head->next;
        temp->next=NULL;
        delete temp;
        length--;
    }
    else if(pos==length)
    {
        temp=head;
        temp1=head;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        count=1;
         while(count<pos)
        {
            temp1=temp1->next;
            count++;
        }
        temp->next=head;
        temp1->next=NULL;
        delete temp1;
        length--;
    }
    else if(pos<length)
    {
        temp=head;
        temp1=head;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        count=1;
         while(count<pos)
        {
            temp1=temp1->next;
            count++;
        }
        temp->next=temp1->next;
        temp1->next=NULL;
        delete temp1;
        length--;

    }

}
void list::insert(int val,int pos)
{
    node *temp;
    node *temp1;
    int count=1;
    if(pos==1 and length==0)
    {
        node *n=new node(val);
        head=n;
        n->next=head;
        length++;
    }
    else if(pos==(length+1))
    {
        temp=head;
        while(count<length)
        {
            temp=temp->next;
            count++;
        }
        node *n=new node(val);
        temp->next=n;
        n->next=head;
        length++;
    }
    else if(pos==1 and length>0)
    {
        count=1;
        temp=head;
        head=new node(val);
        head->next=temp;
        while(count<length)
        {
            temp=temp->next;
            count++;
        }
        temp->next=head;
        length++;
    }
    else if(pos<(length+1))
    {
        temp1=head;
        temp=head;
        while(count<(pos-1))
        {
            temp=temp->next;
            count++;
        }
        node *n=new node(val);
        n->next=temp->next;
        temp->next=n;
        length++;
    }
   
}
void list::print()
{
    node *temp;
    temp=head;
    int count=1;
    while(count<=length)
    {    
        cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
}
int main(void)
{
    list l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(6,5);
    l1.insert(7,6);
    l1.insert(8,7);
    l1.insert(9,8);
    l1.insert(10,9);
    l1.print();
    cout<<endl;
    l1.insert(5,5);
    l1.print();
    cout<<endl;
    l1.del(5);
    l1.print();
    cout<<endl;
    l1.Josephus();
    l1.print();
    return 0;
}