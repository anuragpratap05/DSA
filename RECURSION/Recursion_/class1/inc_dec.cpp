#include <bits/stdc++.h>
using namespace std;

void increasing(int a, int b)
{
    if (a > b)
    {
        return;
    }
    cout << a;
    increasing(a + 1, b);
}

void decreasing(int a, int b)
{
    if (a>b)
    {
        return;
    }
    
    decreasing(a+1 , b);
    cout << a;
}

void inc_dec(int a,int b)
{
    if (a > b)
    {
        return;
    }
    cout<<a;
    inc_dec(a+1,b);
    cout << a ;
}
void odd_even(int a,int b)
{
    if (a > b)
    {
        return;
    }
    if(a%2!=0)
    {
        cout<<a;
    }
    odd_even(a+1,b);
    //cout<<endl;
    if (a % 2 == 0)
    {
        cout << a;
    }
}

int main()
{
    odd_even(5, 9);
    return 0;
}