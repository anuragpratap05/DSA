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

void mergeTwoSortedArrays(vector<int> &nums, int s1, int e1, int s2, int e2)
{
    int i = s1, j = s2;
    vector<int> tempAr(e2 - s1 + 1);
    int k = 0;
    while (i <= e1 and j <= e2)
    {
        if (nums[i] < nums[j])
        {
            tempAr[k] = nums[i];
            i++;
        }
        else
        {
            tempAr[k] = nums[j];
            j++;
        }
        k++;
    }

    while (i <= e1)
    {
        tempAr[k] = nums[i];
        i++;
        k++;
    }

    while (j <= e2)
    {
        tempAr[k] = nums[j];
        j++;
        k++;
    }
    k = 0;
    for (int i = s1; i <= e2; i++)
    {
        nums[i] = tempAr[k];
        k++;
    }
}

void mergeSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;

    mergeSort(nums, s, mid);
    mergeSort(nums, mid + 1, e);
    mergeTwoSortedArrays(nums, s, mid, mid + 1, e);
}

vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    return 0;
}