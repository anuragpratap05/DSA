#include <bits/stdc++.h>
using namespace std;

class heap
{
    vector<int> nums;
    bool maxHeap;

public:
    heap()
    {
        this->maxHeap = true;
    }

    heap(bool maxHeap)
    {
        this->maxHeap = maxHeap;
    }

    int top()
    {
        return this->nums[0];
    }

    bool empty()
    {
        return this->nums.size() == 0;
    }

    bool IsEle1HasHighPriority(int ele1, int ele2)
    {
        if (ele1 > ele2 and this->maxHeap)
        {
            return true;
        }
        if (ele1 < ele2 and !this->maxHeap)
        {
            return true;
        }
        return false;
    }

    void downHeapify(int parIdx)
    {
        int maxEleIdx = parIdx;
        int leftChildIdx = (parIdx * 2) + 1;
        int rightChildIdx = (parIdx * 2) + 2;
        int arraySize = this->nums.size();

        if (leftChildIdx < arraySize and IsEle1HasHighPriority(this->nums[leftChildIdx], this->nums[maxEleIdx]))
        {
            maxEleIdx = leftChildIdx;
        }

        if (rightChildIdx < arraySize and IsEle1HasHighPriority(this->nums[rightChildIdx], this->nums[maxEleIdx]))
        {
            maxEleIdx = rightChildIdx;
        }

        if (maxEleIdx != parIdx)
        {
            swap(this->nums[parIdx], this->nums[maxEleIdx]);
            downHeapify(maxEleIdx);
        }
    }

    void pop()
    {
        int n = this->nums.size();
        swap(this->nums[0], this->nums[n - 1]);
        this->nums.pop_back();
        downHeapify(0);
    }

    void upheapify(int childEleIdx)
    {
        int parEleIdx = (childEleIdx - 1) / 2;
        if (parEleIdx >= 0 and IsEle1HasHighPriority(this->nums[childEleIdx], this->nums[parEleIdx]))
        {
            swap(this->nums[parEleIdx], this->nums[childEleIdx]);
            upheapify(parEleIdx);
        }
    }

    void push(int ele)
    {
        nums.push_back(ele);
        upheapify(this->nums.size() - 1);
    }
};

int main()
{
    heap pq(true);

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