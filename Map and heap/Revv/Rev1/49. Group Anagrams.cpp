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

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<map<char, int>, vector<string>> bigMp;

    for (string &str : strs)
    {
        map<char, int> smallMp;
        for (char ch : str)
            smallMp[ch]++;

        bigMp[smallMp].push_back(str);
        smallMp.clear();
    }

    vector<vector<string>> ans;

    for (auto &p : bigMp)
        ans.push_back(p.second);
    return ans;
}

int main()
{
    return 0;
}