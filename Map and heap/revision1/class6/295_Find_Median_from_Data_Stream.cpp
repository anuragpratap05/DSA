#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>> max_pq;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (max_pq.size() == 0)
        {
            max_pq.push(num);
        }
        else if (num < max_pq.top())
        {
            max_pq.push(num);
        }
        else
        {
            min_pq.push(num);
        }
        int x = min_pq.size() - max_pq.size();
        if (abs(x) > 1)
        {
            if (min_pq.size() > max_pq.size())
            {
                int ele = min_pq.top();
                min_pq.pop();
                max_pq.push(ele);
            }
            else
            {
                int ele = max_pq.top();
                max_pq.pop();
                min_pq.push(ele);
            }
        }
    }

    double findMedian()
    {
        
        if (min_pq.size() == max_pq.size())
        {
            double x = min_pq.top();
            double y = max_pq.top();
            return (x + y) / 2;
        }
        else
        {
            if (min_pq.size() > max_pq.size())
            {
                double ele = max_pq.top();
                return ele;
            }
            else
            {
                double ele = min_pq.top();
                return ele;
            }
        }
    }
};

int main()
{
    MedianFinder f;
    f.addNum(1);
    f.addNum(2);
    cout << f.findMedian();
    cout << "min_pq =  ";
    while (!f.min_pq.empty())
    {
        cout << f.min_pq.top();
        f.min_pq.pop();
    }
    cout << endl;
    cout << "max_pq =  ";
    while (!f.max_pq.empty())
    {
        cout << f.max_pq.top();
        f.max_pq.pop();
    }

    return 0;
}