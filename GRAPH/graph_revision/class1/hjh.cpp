#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(int x) {
        string s1=to_string(x);
        string s2=s1;
        reverse(s1.begin(),s1.end());
        if(s1==s2)
        {
            return true;
        }
        return false;
        
    }

int main()
{
    isPalindrome(121);
    return 0;
}