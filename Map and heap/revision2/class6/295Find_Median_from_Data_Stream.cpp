#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<double> maxPq;
    priority_queue<double, vector<double>, greater<double>> minPq;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {

        if (maxPq.empty() or num < maxPq.top())
        {
            maxPq.push(num);
        }
        else
        {
            minPq.push(num);
        }

        int minPqSize = minPq.size();
        int maxPqSize = maxPq.size();

        if (abs(maxPqSize - minPqSize) > 1)
        {
            if (maxPqSize > minPqSize)
            {
                double ele = maxPq.top();
                maxPq.pop();
                minPq.push(ele);
            }
            else
            {
                double ele = minPq.top();
                minPq.pop();
                maxPq.push(ele);
            }
        }
    }

    double findMedian()
    {
        int minPqSize = minPq.size();
        int maxPqSize = maxPq.size();

        if (maxPqSize == minPqSize)
        {
            double maxEleFromLeftSide = maxPq.top();
            double minEleFromRightSide = maxPq.top();

            return (maxEleFromLeftSide + minEleFromRightSide) / 2.0;
        }
        return (maxPqSize > minPqSize ? maxPq.top() : minPq.top());
    }
};

int main()
{
    double ans = 9 / (double)4;
    cout << ans;
    return 0;
}
