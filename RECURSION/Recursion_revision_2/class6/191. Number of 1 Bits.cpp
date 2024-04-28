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

int hammingWeight(uint32_t n)
{
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        int mask = 1 << i;
        if ((n & mask))
        {
            cnt++;
        }
    }
    return cnt;
}

int hammingWeight2(uint32_t n)
{
    int cnt = 0;
    while (n)
    {
        if ((n & 1))
        {
            cnt++;
        }
        n = (n >> 1);
    }
    return cnt;
}

int hammingWeight3(uint32_t n)
{
    int cnt = 0;
    while (n)
    {

        cnt++;

        n = (n & (n - 1));
    }
    return cnt;
}

int main()
{
    return 0;
}