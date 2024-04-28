#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& numbers, int target)
{
    int n=numbers.size();
    int si=0;
    int ei=n-1;

    while(si<ei)
    {
        if(numbers[si]+numbers[ei]==target)
        {
            return {si+1,ei+1};
        }
        else if(numbers[si]+numbers[ei]<target)
        {
            si++;
        }
        else{
            ei--;
        }
    }
    return {0,0};
}

int main()
{
    return 0;
}