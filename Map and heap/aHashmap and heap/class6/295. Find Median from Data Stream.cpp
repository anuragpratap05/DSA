#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<double> max_type;
    priority_queue<double, vector<double>, greater<double>> min_type;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        int s1 = max_type.size();
        int s2 = min_type.size();
        if (s1 == 0 and s2 == 0)
        {
            max_type.push(num);
        }
        else if (num < max_type.top())
        {
            max_type.push(num);
        }
        else
        {
            min_type.push(num);
        }
        s1 = max_type.size();
        s2 = min_type.size();

        if (abs(s1 - s2) > 1)
        {
            if (s1 > s2)
            {
                int ele=max_type.top();
                max_type.pop();
                min_type.push(ele);
            }
            else{
                int ele = min_type.top();
                min_type.pop();
                max_type.push(ele);
            }
        }
    }

    double findMedian()
    {
        int s1 = max_type.size();
        int s2 = min_type.size();
        if(s1==s2)
        {
            int e1=max_type.top();
            int e2 = min_type.top();
            return  (e1+e2)/2.0;
        }
        return (s1>s2?max_type.top():min_type.top());
        
    }
};

int main()
{
    return 0;
}