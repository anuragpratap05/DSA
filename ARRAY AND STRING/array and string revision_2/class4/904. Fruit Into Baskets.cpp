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

int totalFruit(vector<int> &fruits)
{
    vector<int> freq(100001, 0);
    int i = 0;
    int p = 0;
    int n = fruits.size();
    int len = 0;
    int cnt = 0;
    while (i < n)
    {
        int ele = fruits[i];
        if(freq[ele]==0)
        {
            cnt++;
        }
        freq[ele]++;
        while(cnt>2)
        {
            int nele = fruits[p];
            freq[nele]--;
            if(freq[nele]==0)
            {
                cnt--;
            }
            p++;
        }
        i++;
        len = max(len, i - p);
    }
    return len;
}

int main()
{
    return 0;
}