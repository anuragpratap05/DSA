#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    vector<int> vec;
    unordered_map<int, int> m;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.find(val) == m.end())
        {
            vec.push_back(val);
            m[val] = vec.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            int idx = m[val];

            swap(vec[vec.size() - 1], vec[idx]);
            m.erase(val);
            if (idx != vec.size() - 1)
            {
                m[vec[idx]] = idx;
            }

            vec.pop_back();
            return true;
        }
        return false;
    }

    int getRandom()
    {
        
        int idx = rand() % vec.size();
        return vec[idx];
    }
};
int main()
{
    return 0;
}