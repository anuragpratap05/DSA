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

vector<int> allIndex(vector<int> &arr, int idx, int data, int count)
{
    if(idx==arr.size())
    {
        vector<int> vec(count);
        return vec;
    }
    if(arr[idx]==data)
    {
        count++;
    }
    vector<int > ans=allIndex(arr,idx+1,data,count);
    if(arr[idx]==data)
    {
        ans[count-1]=idx;

    }
    return ans;
}

int main()
{
    return 0;
}