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

int maxLen(int arr[], int N)
{
    vector<int> freq(N + 1, 1e6);
    int cumSum = 0, maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            cumSum -= 1;
        }
        else
        {
            cumSum += 1;
        }

        if (cumSum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }
        int mappedCusmSum = cumSum < 0 ? N + cumSum : cumSum;
        if (freq[mappedCusmSum] == 1e6)
        {
            freq[mappedCusmSum] = i;
        }
        else
        {
            maxLen = max(maxLen, i - freq[mappedCusmSum]);
        }
    }
    return maxLen;
}

int main()
{
    return 0;
}