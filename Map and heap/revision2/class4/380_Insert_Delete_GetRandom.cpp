#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    unordered_map<int, int> mp;
    vector<int> nums;

public:
    RandomizedSet()
    {
        mp.clear();
        nums.clear();
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
            return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
            return false;
        int eleIdxInNums = mp[val];
        if (eleIdxInNums == nums.size() - 1)
        {
            mp.erase(val);
            nums.pop_back();
        }
        else
        {
            mp.erase(val);
            int lastEleOfNums = nums[nums.size() - 1];
            swap(nums[eleIdxInNums], nums[nums.size() - 1]);
            nums.pop_back();
            mp[lastEleOfNums] = eleIdxInNums;
        }

        return true;
    }

    int getRandom()
    {
        int N = nums.size();
        int randomIdx = rand() % N;
        return nums[randomIdx];
    }
};

int main()
{
    int N = 11;
    // This program will create some sequence of random
    // numbers on every program run within range 0 to N-1
    // for (int i = 0; i < 9; i++)
    cout << rand() % N << " ";
    return 0;
}