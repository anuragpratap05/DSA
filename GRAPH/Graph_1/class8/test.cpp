#include<bits/stdc++.h>
using namespace std;




int main()
{
    int i,j;
    for(int i=0;i<5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cout<<j;
        }
        cout<<i;
    }
    // priority_queue<int, vector<int>, greater<int>> pq;
    // pq.push(6);
    // pq.push(6);
    // pq.push(37);
    // pq.push(74);
    // pq.push(79);
    // pq.push(10);
    // pq.push(96);
    // pq.push(43);

    // priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> >pq;
    // pq.push({16,37,38});
    // pq.push({86,37,38});
    // pq.push({28,37,38});
    // pq.push({29,37,38});
    // pq.push({1,37,38});
    // pq.push({63,37,38});
    // pq.push({91,37,38});

    // while(!pq.empty())
    // {
    //     vector<int> vec=pq.top();
    //     for(auto e:vec)
    //     {
    //         cout<<e<<" ";
    //     }
    //     cout<<endl;
    //     pq.pop();
    // }
    return 0;
}