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

class heap
{
    vector<int> nums;
    bool isMaxHeap = true;

public:
    heap(bool isMaxHeap)
    {
        this->isMaxHeap = isMaxHeap;
    }

    bool isEle1HasHighpriority(int ele1, int ele2)
    {
        if (isMaxHeap && ele1 > ele2)
            return true;

        if (!isMaxHeap && ele1 < ele2)
            return true;
        return false;
    }

    void upHeapify(int childIdx)
    {
        int parIdx = (childIdx - 1) / 2;
        if (parIdx >= 0 and this->isEle1HasHighpriority(this->nums[childIdx], this->nums[parIdx]))
        {
            swap(this->nums[childIdx], this->nums[parIdx]);
            upHeapify(parIdx);
        }
    }

    void downHeapify(int parIdx)
    {
        int highPriorityIdx = parIdx;

        int lci = (2 * parIdx) + 1;
        int rci = (2 * parIdx) + 2;

        if (lci < this->nums.size() && this->isEle1HasHighpriority(this->nums[lci], this->nums[highPriorityIdx]))
            highPriorityIdx = lci;
        if (rci < this->nums.size() && this->isEle1HasHighpriority(this->nums[rci], this->nums[highPriorityIdx]))
            highPriorityIdx = rci;

        if (highPriorityIdx != parIdx)
        {
            swap(this->nums[parIdx], this->nums[highPriorityIdx]);
            downHeapify(highPriorityIdx);
        }
    }

    bool empty()
    {
        return this->nums.size() == 0;
    }

    void push(int ele)
    {
        this->nums.push_back(ele);
        upHeapify(this->nums.size() - 1);
    }

    void pop()
    {

        int n = this->nums.size();
        swap(this->nums[0], this->nums[n - 1]);
        this->nums.pop_back();
        downHeapify(0);
    }

    int top()
    {
        if (!empty())
            return this->nums[0];
        else
        {
            cout << "PQ is already empty";
        }
        return -10000;
    }
};

void downHeapify(int parIdx, vector<int> &nums, int n)
{
    int maxidx = parIdx;

    int lci = (2 * parIdx) + 1;
    int rci = (2 * parIdx) + 2;

    if (lci < n && nums[lci] > nums[maxidx])
        maxidx = lci;
    if (rci < n && nums[rci] > nums[maxidx])
        maxidx = rci;

    if (maxidx != parIdx)
    {
        swap(nums[parIdx], nums[maxidx]);
        downHeapify(maxidx, nums, n);
    }
}

void heapSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        downHeapify(i, nums, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        downHeapify(0, nums, i);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    heapSort(nums);
    return nums;
}

int main()
{

    heap pq(false);

    pq.push(10);
    pq.push(3);
    pq.push(135);
    pq.push(145);
    pq.push(125);
    pq.push(154);
    pq.push(115);
    pq.push(15);
    pq.push(1524);
    pq.push(15433);
    pq.push(1543);

    // for (int ele : pq.nums)
    // {
    //     cout << ele << ' ';
    // }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}