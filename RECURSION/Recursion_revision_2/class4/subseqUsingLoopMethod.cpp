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

void subsequenceHelper(string str, int idx, vector<string> &ans,string psf)
{
    
    cout << psf << endl;
    for (int i = idx; i < str.size();i++)
    {
        subsequenceHelper(str, i + 1, ans, psf + str[i]);
    }
}

void subsequence(string str, int idx, vector<string> &ans)
{
    subsequenceHelper(str,idx,ans,"");
}

int main()
{
    vector<string> ans;
    subsequence("abc", 0, ans);
    return 0;
}