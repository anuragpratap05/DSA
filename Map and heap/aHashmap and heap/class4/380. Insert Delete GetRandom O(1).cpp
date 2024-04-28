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

class RandomizedSet
{
public:
    vector<int> vec;
    unordered_map<int,int>m;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if(m.find(val)==m.end())
        {
            vec.push_back(val);
            m[val]=vec.size()-1;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if(m.find(val)!=m.end())
        {
            int idx=m[val];
            
            swap(vec[idx],vec[vec.size()-1]);
            vec.pop_back();
            if(vec.size()!=0)
            {
                m[vec[idx]]=idx;
            }
            m.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int idx=rand()%vec.size();
        return vec[idx];
    }
};

int main()
{
    return 0;
}