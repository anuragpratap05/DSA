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

int subarraysDivByK(vector<int> &nums, int k)
{
    int subarrayCnt = 0;
    vector<int> freq(k,0);
    freq[0] = 1;
    int sumSoFar = 0;
    for (int ele : nums)
    {
        sumSoFar += ele;
        int modulo = sumSoFar % k;
        if (modulo < 0)
            modulo += k;
        if (freq[modulo]!=0)
            subarrayCnt += freq[modulo];
        freq[modulo]++;
    }
    return subarrayCnt;
}

int main()
{
    return 0;
}