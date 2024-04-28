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

int trap(vector<int> &height)
{
    int n = height.size();

    vector<int> maxOnRight(n, 0);
    vector<int> maxOnLeft(n, 0);

    int maxBuildingRight = height[n - 1];
    int maxBuildingLeft = height[0];
    for (int i = n - 2; i >= 0; i--)
    {
        int curBuilding = height[i];
        if (curBuilding < maxBuildingRight)
            maxOnRight[i] = maxBuildingRight;
        else
            maxBuildingRight = curBuilding;
    }

    for (int i = 1; i < n; i++)
    {
        int curBuilding = height[i];
        if (curBuilding < maxBuildingLeft)
            maxOnLeft[i] = maxBuildingLeft;
        else
            maxBuildingLeft = curBuilding;
    }

    int water = 0;

    for (int i = 0; i < n; i++)
    {
        int curHt = height[i];
        int minSupport = min(maxOnLeft[i], maxOnRight[i]);
        water += minSupport - curHt > 0 ? minSupport - curHt : 0;
    }
    return water;
}

int trap2(vector<int> &height)
{
    stack<int> st;
    st.push(-1);
    int water = 0;

    for (int i = 0; i < height.size(); i++)
    {
        int curHt = height[i];
        while (st.top() != -1 and height[st.top()] <= curHt)
        {
            int poppedidx = st.top();
            st.pop();
            int popBuildingHt = height[poppedidx];
            int width = (i - st.top()) - 1;
            int minSupport = min(curHt, st.top() == -1 ? -1 : height[st.top()]);
            int ht = minSupport - popBuildingHt;
            water += width * ht > 0 ? width * ht : 0;
        }
        st.push(i);
    }
    return water;
}

int main()
{
    return 0;
}