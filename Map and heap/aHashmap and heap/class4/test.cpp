#include<bits/stdc++.h>
using namespace std;




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

int main()
{
    priority_queue<trp,vector<trp>, trp::compare> pq;
    pq.push(trp(0,8,24));
    pq.push(trp(3,3,21));
    pq.push(trp(5,3,21));
    pq.push(trp(1,14,22));
    pq.push(trp(7,11,27));
    while(!pq.empty())
    {
        trp t = pq.top();
        pq.pop();
        cout<<  t.val<<" ";
        cout<<  t.freq<<" ";
        cout<<  t.idx<<" ";
        cout<<endl;
    }
    return 0;
}