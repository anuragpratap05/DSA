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

int max_sum(int A[], int N)
{
    int a_sum = 0;
    int sum = 0;
    int maxi = sum;
    for (int i = 0; i < N; i++)
    {
        a_sum += A[i];
        sum += (i * A[i]);
    }

    for (int i = 0; i < N;i++)
    {
        sum = (sum - (a_sum - A[i])) + (A[i] * N - 1);
        maxi = max(sum, maxi);
    }
    return maxi;
}

int main()
{
    return 0;
}