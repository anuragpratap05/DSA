#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    // ele,i
    stack<pair<int, int>> st;
    int i;

public:
    StockSpanner()
    {
        this->st.push({-1, -1});
        this->i = 0;
    }

    int next(int price)
    {
        while (this->st.top().first != -1 and price >= this->st.top().first)
        {
            st.pop();
        }
        int span = this->i - this->st.top().second;
        this->st.push({price, i});
        this->i++;
        return span;
    }
};

int main()
{
    return 0;
}