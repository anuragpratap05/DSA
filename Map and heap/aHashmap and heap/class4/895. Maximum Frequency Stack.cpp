#include <bits/stdc++.h>
using namespace std;

//O(1) time
class FreqStack
{
public:
    unordered_map<int, int> m;
    int freq = 0;
    vector<stack<int>> v;
    FreqStack()
    {
    }

    void push(int val)
    {
        
        m[val]++;
        if (m[val] > freq)
        {
            freq++;
            stack<int> s;
            v.push_back(s);
        }
        v[m[val]-1].push(val);
        
    }

    int pop()
    {
        int idx=freq-1;
        int ele=v[idx].top();
        m[ele]--;
        if(m[ele]==0)
        {
            m.erase(ele);
        }
        v[idx].pop();
        if (v[idx].size()==0)
        {
            freq--;
            v.pop_back();
        }
        return ele;
    }
};

// log(N) time
class FreqStack2
{
    class trp
    {
    public:
        int val, freq, idx;

        trp(int val, int freq, int idx)
        {
            this->val = val;
            this->freq = freq;
            this->idx = idx;
        }

        struct compare
        {
            /* data */
            bool operator()(const trp &t1, const trp &t2) const
            {
                if (t1.freq == t2.freq)
                {
                    return t1.idx < t2.idx;
                }
                return t1.freq < t2.freq;
            }
        };
    };

public:
    FreqStack2()
    {
    }
    priority_queue<trp, vector<trp>, trp::compare> pq;
    map<int, int> m;
    int idx = 0;
    void push(int val)
    {
        m[val]++;
        pq.push(trp(val, m[val], idx++));
    }

    int pop()
    {
        trp t = pq.top();
        pq.pop();
        int val = t.val;
        int freq = t.freq;
        int idx = t.idx;
        m[val]--;
        if (m[val] == 0)
        {
            m.erase(val);
        }
        return val;
    }
};

int main()
{
    return 0;
}