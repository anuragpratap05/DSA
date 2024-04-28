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

void subseq(string str, string ans, int idx)
{

    if (idx == str.size())
    {
        cout << ans << endl;
        return;
    }

    subseq(str, ans, idx + 1);
    subseq(str, ans + str[idx], idx + 1);
}

int main()
{
    subseq("abc", "",0);
    return 0;
}