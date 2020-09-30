#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
bool pal(string x,char *ptr1,char *ptr2,int y)
{
    if(*ptr1==*ptr2)
    {
        if(y==0)
        {
            return true;
        }
        y--;
        ptr1++;
        ptr2--;
        return pal(x,ptr1,ptr2,y);
    }
    else if(*ptr1!=*ptr2)
    {
        return false;
    }
}
int main(void)
{
    char *ptr1,*ptr2;
    string x="1001";
    int y=x.length()/2;
    ptr1=&x[0];
    ptr2=ptr1+x.length()-1;
    cout<<pal(x,ptr1,ptr2,y);
    return 0;
}