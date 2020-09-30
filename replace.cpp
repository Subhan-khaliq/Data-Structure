#include<iostream>
using namespace std;
const int x=1;
const int size=5;
int arr[size]={1,2,1,1,2};
int rep(int *ptr1,int *ptr2,int y,int x)
{
    int z;
     if(ptr1==ptr2 and ptr2==(arr+size)-1)
        {
            ptr2--;
        }
    if(y==0)
    {
        return true;
    }
    else
    {
        *ptr1=*ptr2*x;
        z=*ptr1;
        ptr2--;
        y--;
        if(ptr2==arr-1)
        {
            return true;
        }
        else if(ptr1==ptr2 and ptr1==arr)
        {
            return true;
        }
        else if(ptr1==ptr2 and ptr1!=arr)
        {
            ptr2--;
            return rep(ptr1,ptr2,y,z);
        }
        return rep(ptr1,ptr2,y,z);
    }
}
int replace(int *ptr1,int *ptr2,int z)
{
    if(z==0)
    {
        return true;
    }
    rep(ptr1,ptr2,size,x);
    ptr1++;
    ptr2=(arr+size)-1;
    z--;
    return replace(ptr1,ptr2,z);
}
int main(void)
{
    int *ptr,*ptr1;
    ptr=arr;
    ptr1=(arr+size)-1;
    replace(ptr,ptr1,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}