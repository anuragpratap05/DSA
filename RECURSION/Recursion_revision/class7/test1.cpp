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

int main()
{
    // string str = "ABCD";
    // string ques = str.substr(1, 1);
    // cout << ques;
    int dig = 7;
    char ch = dig + '0';
    cout << ch << endl;
    string str = "123456";
    str += ch;
    cout << str;

    return 0;
}