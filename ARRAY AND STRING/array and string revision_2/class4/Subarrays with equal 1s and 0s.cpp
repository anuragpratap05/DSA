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

// using map
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        if (ele == 0)
        {
            ele = -1;
        }
        sum += ele;
        if (m.find(sum) != m.end())
        {
            ans += m[sum];
        }
        m[sum]++;
    }
    return ans;
}


// using array
// modulus will map to unique index of frequency don't worry indexes will not be repeated after modulus with normal sum because k will inc.
long long int countSubarrWithEqualZeroAndOne_2(int arr[], int n)
{
    vector<int> freq(n + 1, 0);
    freq[0] = 1;
    int k = n + 1;
    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        if (ele == 0)
        {
            ele = -1;
        }
        sum += ele;

        // sum=(sum+k)%k;

        int rem = sum;
        if (rem < 0)
        {
            rem = (rem + k) % k;
        }

        //  cout<<rem<<endl;

        ans += freq[rem];

        freq[rem]++;
    }
    return ans;
}

int main()
{
    return 0;
}