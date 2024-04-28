#include <bits/stdc++.h>
using namespace std;
int c = 0;
void solution(int i, int n, int k, int rmsets, vector<vector<int>> &ans)
{
    if (i > n)
    {
        if (rmsets == k)
        {
            c++;
            cout << c << ". ";
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
            ans[idx].push_back(i);
            solution(i + 1, n, k, rmsets, ans);
            ans[idx].pop_back();
        }
        else
        {
            ans[idx].push_back(i);
            solution(i + 1, n, k, rmsets + 1, ans);
            ans[idx].pop_back();
            break;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(k, vector<int>());
    solution(1, n, k, 0, ans);
    return 0;
}