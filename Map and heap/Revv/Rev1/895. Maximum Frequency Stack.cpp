#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
    vector<stack<int>> stacksArr;
    unordered_map<int, int> mp;

public:
    FreqStack()
    {
        stack<int> st;
        this->stacksArr.push_back(st);
    }

    void push(int val)
    {
        mp[val]++;
        int curNumFreq = mp[val];
        if (curNumFreq == stacksArr.size())
        {
            stack<int> st;
            this->stacksArr.push_back(st);
        }
        stacksArr[curNumFreq].push(val);
    }

    int pop()
    {
        int highestFreq = this->stacksArr.size() - 1;
        stack<int> &highestFreqStack = this->stacksArr[highestFreq];
        int highestPriorityEle = highestFreqStack.top();
        highestFreqStack.pop();
        if (highestFreqStack.empty())
            stacksArr.pop_back();
        if (--mp[highestPriorityEle] == 0)
            mp.erase(highestPriorityEle);
        return highestPriorityEle;
    }
};

int main()
{
    return 0;
}