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
int minDistanceHelp(string word1, string word2, int i, int j)
{
    if (i == word1.size() or j == word2.size())
    {
        if (i == word1.size())
            return word2.size() - j;
        return word1.size() - i;
    }

    if (word1[i] == word2[j])
    {
        return minDistanceHelp(word1, word2, i + 1, j + 1);
    }
    else
    {
        int ins = minDistanceHelp(word1, word2, i + 1, j + 1);
        int del = minDistanceHelp(word1, word2, i + 1, j);
        int rep = minDistanceHelp(word1, word2, i + 1, j + 1);
        return min(ins, min(del, rep)) + 1;
    }
}

int minDistance(string word1, string word2)
{
    return minDistanceHelp(word1, word2, 0, 0);
}

int main()
{
    return 0;
}