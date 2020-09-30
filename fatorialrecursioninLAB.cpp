#include<iostream>
using namespace std;
int fic(int n)
{
    if(n==0)
    {
        return true;
    }
    return n*fic(n-1);
}
int main(void)
{
    cout<<fic(6);
    return 0;
}