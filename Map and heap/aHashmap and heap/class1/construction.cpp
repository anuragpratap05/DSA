#include <bits/stdc++.h>
using namespace std;


class heap
{
    vector<int> arr;
    bool isMaxHeap;
    // int n;
    void defaultValue(bool isMaxHeap)
    {
        // n=arr.size();
        this->isMaxHeap = isMaxHeap;
    }
    void constructHeap()
    {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            downheapify(i);
        }
    }
    bool compare(int a, int b)
    {
        if (isMaxHeap)
            return a > b;
        return a < b;
    }
    void downheapify(int pi)
    {
        int n = arr.size();
        int maxidx = pi;
        if ((2 * pi) + 1 < n and compare(arr[(2 * pi) + 1], arr[maxidx]))
        {
            maxidx = (2 * pi) + 1;
        }

        if ((2 * pi) + 2 < n and compare(arr[(2 * pi) + 2], arr[maxidx]))
        {
            maxidx = (2 * pi) + 2;
        }
        if (maxidx != pi)
        {
            swap(this->arr[maxidx], this->arr[pi]);
            downheapify(maxidx);
        }
    }

    void upheapify(int ci)
    {
        int pi = (ci - 1) / 2;
        if (pi >= 0 and compare(arr[ci], arr[pi]))
        {
            swap(this->arr[pi], this->arr[ci]);
            upheapify(pi);
        }
    }

public:
    heap()
    {
        defaultValue(true);
    }

    heap(bool isMaxHeap)
    {
        defaultValue(isMaxHeap);
    }

    heap(vector<int> &arr, bool isMaxHeap)
    {
        defaultValue(isMaxHeap);

        for (int ele : arr)
            this->arr.push_back(ele);

        constructHeap();
    }
    int size()
    {
        return arr.size();
    }
    int top()
    {
        return arr[0];
    }
    void push(int val)
    {
        arr.push_back(val);
        int n = arr.size();
        upheapify(n - 1);
    }

    void pop()
    {
        int n = arr.size();
        swap(arr[0], arr[n - 1]);
        arr.pop_back();
        downheapify(0);
    }
};

int main()
{
    vector<int>vec={27,45,3,5,4,3,5,3,334,5,3,-2};
    heap pq(vec,true);

    // pq.push(76);
    // pq.push(47);
    // pq.push(23);
    // pq.push(73);
    // pq.push(723);
    // pq.push(756);
    // pq.push(62);

    while (pq.size() > 0)
    {
        cout << pq.top() << "  ";
        pq.pop();
    }

    return 0;
}
