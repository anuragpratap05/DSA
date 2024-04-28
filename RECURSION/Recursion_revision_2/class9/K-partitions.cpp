#include<bits/stdc++.h>
using namespace std;

bool isValidAns(vector<vector<int>> ans)
{
    for(vector<int>& vec:ans)
    {
        if(!vec.size())
        {
            return false;
        }
    }
    return true;
}
void display(vector<vector<int>> &ans)
{
    for (vector<int> &vec : ans)
    {
        cout << "[";
        for (int i = 0; i < vec.size(); i++)
        {
            int e = vec[i];
            cout << e;
            if (i < vec.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;
}

int  KPartition(vector<vector<int>> ans,int n,int cNum)
{   
    if(cNum>n)
    {
        if(isValidAns(ans))
        {
            display(ans);
            return 1;
        }
        return 0;
    }

    int cnt = 0;
    for (vector<int> &subset : ans)
    {
        subset.push_back(cNum);
        cnt += KPartition(ans, n, cNum + 1);
        subset.pop_back();
        if(subset.size()==0)
        {
            break;
        }
    }
    return cnt;
}

int main()
{
    // int n,k;
    // cin>>n>>k;
    int n = 4;
    int k = 3;
    vector<vector<int>> ans(k, vector<int>());
    cout<<KPartition(ans, n, 1);
    return 0;
}