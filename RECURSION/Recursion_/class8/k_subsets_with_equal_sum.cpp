#include <bits/stdc++.h>
using namespace std;

void solution(vector<int>& arr,int i, int n, int k, int rmsets, vector<vector<int>> &ans,vector<int>& sum)
{
    if (i == n)
    {
        if (rmsets == k)
        {
            int csum=sum[0];
            for(int i=1;i<k;i++)
            {
                if(sum[i-1]!=sum[i])
                {
                    return;
                }
            }
            
            // count++;
            // cout<<count<<".";
            for (auto &vec : ans)
            {
                cout << "[";
                for (int x = 0; x < vec.size(); x++)
                {
                    cout << vec[x];
                    if (x != vec.size() - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << "] ";
            }
            cout << endl;
        }

        return;
    }
    for (int idx = 0; idx < k; idx++)
    {
        if (ans[idx].size() != 0)
        {
            ans[idx].push_back(arr[i]);
            sum[idx]+=arr[i];
            solution(arr,i + 1, n, k, rmsets, ans,sum);
            sum[idx]-=arr[i];
            ans[idx].pop_back();
        }
        else
        {
            ans[idx].push_back(arr[i]);
            sum[idx]+=arr[i];
            solution(arr,i + 1, n, k, rmsets + 1, ans,sum);
            sum[idx]-=arr[i];
            ans[idx].pop_back();
            break;
        }
    }
}

int main()
{
    int n, k;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    vector<vector<int>> ans(k, vector<int>());
    vector<int>sum(k,0);
    solution(arr,0, n, k, 0, ans,sum);
    return 0;
}