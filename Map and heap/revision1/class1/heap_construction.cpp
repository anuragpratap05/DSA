#include <bits/stdc++.h>
using namespace std;

class heap
{
    vector<int> arr;
    bool is_maxheap = true;

public:
    void set_default(bool is_maxheap)
    {
        this->is_maxheap = is_maxheap;
    }

    heap()
    {
        set_default(true);
    }

    heap(bool is_maxheap)
    {
        set_default(is_maxheap);
    }

    heap(vector<int> nums, bool is_maxheap)
    {
        for (int e : nums)
        {
            this->arr.push_back(e);
        }
        set_default(is_maxheap);
        construct_heap();
    }

    void construct_heap()
    {
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            down_heapify(i);
        }
    }

    int size()
    {
        return this->arr.size();
    }

    bool empty()
    {
        return this->arr.size() == 0;
    }

    void pop()
    {
        swap(this->arr[0], this->arr[arr.size() - 1]);
        arr.pop_back();
        down_heapify(0);
    }

    int top()
    {
        return this->arr[0];
    }

    bool compare_to(int i, int j)
    {
        if (this->arr[i] > this->arr[j] and this->is_maxheap)
        {
            return true;
        }

        if (this->arr[i] < this->arr[j] and !this->is_maxheap)
        {
            return true;
        }
        return false;
    }

    void down_heapify(int pi)
    {
        int maxidx = pi;
        int lc = (pi * 2) + 1;
        int rc = (pi * 2) + 2;

        if (lc < this->arr.size() and compare_to(lc, maxidx))
        {
            maxidx = lc;
        }

        if (rc < this->arr.size() and compare_to(rc, maxidx))
        {
            maxidx = rc;
        }

        if (maxidx != pi)
        {
            swap(this->arr[pi], this->arr[maxidx]);
            down_heapify(maxidx);
        }
    }

    void upheapify(int ci)
    {
        int pi = (ci - 1) / 2;
        if (pi >= 0 and compare_to(ci, pi))
        {
            swap(this->arr[pi], this->arr[ci]);
            upheapify(pi);
        }
    }

    void push(int val)
    {
        this->arr.push_back(val);
        upheapify(this->arr.size() - 1);
    }
};

int main()
{
    // vector<int> nums = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    // heap pq(nums,true);

    // while(!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

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
    // for (int ele : pq.arr)
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