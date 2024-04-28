#include <bits/stdc++.h>
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
    int n = asteroids.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele = asteroids[i];
        if (ele > 0)
        {
            st.push(ele);
        }
        else
        {
            if (st.empty() or st.top() < 0)
            {
                st.push(ele);
            }
            else
            {
                while (!st.empty() and st.top() > 0 and abs(st.top()) < abs(ele))
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    if (st.top() < 0)
                    {
                        st.push(ele);
                    }
                    else
                    {
                        if (abs(st.top()) == abs(ele)) // doni destroy
                        {
                            st.pop();
                        }
                        else
                        {
                        }
                    }
                }
                else
                {
                    st.push(ele);
                }
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}