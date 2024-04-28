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

vector<int> twoSum(vector<int> &numbers, int target)
{
    int s = 0, e = numbers.size() - 1;
    while (s <= e)
    {
        int curSum = numbers[s] + numbers[e];
        if (curSum == target)
            return {s, e};
        if (curSum > target)
            e--;
        else
            s++;
    }
}

int main()
{
    return 0;
}