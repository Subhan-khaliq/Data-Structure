#include<iostream>
using namespace std;
const int size=5;
class Queue
{
    private:
    int *arr;
    int *front;
    int *rear;
    int length;
    public:
    Queue()
    {
        arr=new int[size];
        front=NULL;
        rear=NULL;
        length=0;
    }
    void in_que(int val);
    int de_que();
};
void Queue::in_que(int val)
{
    if(length==size)
    {
        cout<<"overflow";
        return;
    }
    if(rear==arr+(size-1))
    {
        rear=arr;
        *rear=val;
        length++;
    }
    else if(rear==NULL)
    {
        rear=arr;
        front=arr;
        front--;
        *rear=val;
        length++;
    }
    else
    {
        rear++;
        *rear=val;
        length++;
    }
    
}
int Queue::de_que()
{
    int *temp;
    if(front==arr+(size-1) and rear!=arr+(size-1))
    {
        front=arr;
        temp=front;
         length--;
        return *temp;
    }
    if(front==arr+(size-1) and length==size)
    {
        front=arr;
        temp=front;
         length--;
       return *temp;
    }
    else if(rear==front and length==0)
    {
        cout<<"Underflow";
        return 1;
    }
    else
    {
        front++; 
        temp=front;
         length--;
        return *temp;  
    }
}
int main(void)
{
    Queue l1;
    l1.in_que(1);
    l1.in_que(2);
    l1.in_que(3);
    l1.in_que(4);
    l1.in_que(5);
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    cout<<l1.de_que();
    return 0;
}