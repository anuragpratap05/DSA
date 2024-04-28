#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
    this->val = val;
    }
};

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n=asteroids.size();
    if(n==0)
    {
        return {};
    }
    stack<int>st;
    int i=0;
    while(i<n)
    {
        if(st.empty())
        {
            st.push(asteroids[i]);
        }
        else{
            if(asteroids[i]<0)
            {
                while (!st.empty() and st.top() > 0 and st.top() < abs(asteroids[i]))
                {
                    st.pop();
                }
                if (!st.empty() and st.top() > 0 and st.top() == abs(asteroids[i]))
                {
                    st.pop();
                    i++;
                    continue;
                }
                if (!st.empty() and st.top() > 0 and st.top() > abs(asteroids[i]))
                {
                    //st.pop();
                    i++;
                    continue;
                }
            }
            
                st.push(asteroids[i]);
            
            
        }
        i++;
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    return 0;
}