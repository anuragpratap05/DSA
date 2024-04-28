#include <bits/stdc++.h>
using namespace std;

//O(log)
class FreqStack
{
public:
    class compa
    {
    public:
        bool operator()(const vector<int> &vec1, const vector<int> &vec2) const
        {
            if (vec1[1] == vec2[1])
            {
                return vec2[2] > vec1[2];
            }
            return vec2[1] > vec1[1];
        }
    };
    unordered_map<int, int> m;
    priority_queue<vector<int>, vector<vector<int>>, compa> pq;
    int idx = 0;

    FreqStack()
    {
    }

    void push(int val)
    {
        
        m[val]++;
        vector<int> vec(3, 0);
        vec[0] = val;
        vec[1] = m[val];
        vec[2] = idx;
        pq.push(vec);
        idx++;
    }

    int pop()
    {
        vector<int> vec = pq.top();
        pq.pop();
        int val = vec[0];
        m[val]--;
        return val;
    }
};
//O(1)
class FreqStack2
{
public:
    unordered_map<int, int> m;
    vector<stack<int>> vec;
    int maxi = 0;
    FreqStack2()
    {
    }

    void push(int val)
    {
        m[val]++;
        if(m[val]>maxi)
        {
            maxi = m[val];
            stack<int> s;
            vec.push_back(s);
        }
        vec[m[val]-1].push(val);
    }

    int pop()
    {
        stack<int>& st = vec[vec.size() - 1];
        int ans= st.top();
        m[ans]--;
        st.pop();
        if(st.size()==0)
        {
            vec.pop_back();
            maxi--;
        }
        return ans;
    }

    
};

int main()
{
    FreqStack2 f;
    f.push(5);
    f.push(7);
    f.push(5);
    f.push(7);
    f.push(4);
    f.push(5);
    cout << "ans=" << f.pop() << endl;
    cout << "ans=" << f.pop() << endl;

    for (auto &st : f.vec)
    {
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

    return 0;
}