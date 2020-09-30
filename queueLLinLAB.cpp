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
class Queue
{
    private:
        int length;
        node *front;
        node *rear;
    public:
    Queue()
    {
        length=0;
        front=NULL;
        rear=NULL;
    }
    void in_que(int val);
    int de_que();
};
void Queue::in_que(int val)
{
    node *temp;
    if(length==10)
    {
        cout<<"Overflow ";
        return ;
    }
    else if(front==NULL)
    {
        node *n=new node(val);
        front=n;
        rear=n;
        length++;
    }
    else
    {
    node *n=new node(val);
    temp=rear;
    temp->next=n;
    rear=n;
    length++;
    }
}
int Queue::de_que()
{
    node *temp;
    int x;
    if(front==NULL)
    {
        cout<<"Underflow ";
        return 1;
    }
    else
    {
    temp=front;
    front=front->next;
    temp->next=NULL;
    x=temp->data;
    delete temp;
    return x;
    }
}
int main(void)
{
    Queue l1;
    l1.in_que(2);
    l1.in_que(5);
    l1.in_que(7);
    l1.in_que(8);
    l1.in_que(9);
    l1.in_que(10);
    l1.in_que(11);
    l1.in_que(12);
    l1.in_que(13);
    l1.in_que(14);
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    return 0;
}