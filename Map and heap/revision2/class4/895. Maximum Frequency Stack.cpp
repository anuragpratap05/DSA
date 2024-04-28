#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
    vector<stack<int>> vec;
    unordered_map<int, int> mp;
    int maxmFreqTillNow = 0;

public:
    FreqStack()
    {
    }

    void push(int val)
    {
        mp[val]++;
        if (mp[val] > maxmFreqTillNow)
        {
            maxmFreqTillNow = mp[val];

            stack<int> st;
            vec.push_back(st);
        }
        int freqOfVal = mp[val];
        vec[freqOfVal - 1].push(val);
    }

    int pop()
    {
        int highestFreqStackIdx = vec.size() - 1;
        stack<int> &highestFreqStack = vec[highestFreqStackIdx];
        int highestFreqEle = highestFreqStack.top();
        highestFreqStack.pop();
        mp[highestFreqEle]--;
        if (highestFreqStack.empty())
        {
            vec.pop_back();
            maxmFreqTillNow--;
        }
        return highestFreqEle;
    }
};

int main()
{
    return 0;
}