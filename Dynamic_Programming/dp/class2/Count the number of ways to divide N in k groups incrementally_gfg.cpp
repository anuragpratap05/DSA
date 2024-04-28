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

int devideIntoKHelp(int N, int k, int idx, int n)
{
    if (n == 0 and k == 0)
        return 1;
    int count = 0;
    for (int num = idx; num <= N; num++)
    {
        if (n - num >= 0)
            count += devideIntoKHelp(N, k - 1, num, n - num);
        else
            break;
    }
    return count;
}

int devideintoK(int N, int k)
{
    return devideIntoKHelp(N, k, 1, N);
}

int main()
{
    cout << "ans--> " << devideintoK(24, 5) << endl;
    return 0;
}