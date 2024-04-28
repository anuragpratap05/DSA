#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    vector<int> nums;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
        this->nums.clear();
        this->mp.clear();
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
            return false;
        this->nums.push_back(val);
        this->mp[val] = this->nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
            return false;
        int arrIdx = mp[val];
        mp.erase(val);
        if (arrIdx == nums.size() - 1)
        {
            this->nums.pop_back();
        }
        else
        {
            int lastEleofNums = this->nums[nums.size() - 1];
            swap(this->nums[arrIdx], this->nums[nums.size() - 1]);
            this->nums.pop_back();
            mp[lastEleofNums] = arrIdx;
        }
        return true;
    }
    int getRandomIndex(int vectorSize)
    {
        return std::rand() % vectorSize;
    }

    int getRandom()
    {

        // Seed the random number generator
        std::srand(std::time(0));

        // Generate a random index
        int randomIndex = getRandomIndex(this->nums.size());

        // Access the random element
        int randomElement = this->nums[randomIndex];
        return randomElement;
    }
};

int main()
{
    return 0;
}