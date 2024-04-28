#include<bits/stdc++.h>
using namespace std;




int main()
{
    map<int,int> m;

    for(int i=1;i<5;i++)
    {
        m[i]++;
        if(i%2==0)
        {
            m[i]++;
        }
    }

    // for(int i=1;i<m.size();i++)
    // {
    //     cout<<m[i].first<<"->"<<m[i].second<<endl;
    // }
    if(m[0]==0)
    {
        cout<<"nhi hai 0"<<endl;
    }

    for(auto p:m)
    {
        cout<<p.first<<"->"<<p.second<<endl;
    }
    cout<<m[0]<<endl;

    return 0;
}