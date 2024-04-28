#include<bits/stdc++.h>
using namespace std;




double help(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double sa = help(x, n / 2);
    double ans = sa * sa;
    if (n % 2 == 0)
    {
        return ans;
    }
    return ans * x;
}
double myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
        n = abs(n);
    }
    return help(x, n);
}


int main()
{
    
    return 0;
}