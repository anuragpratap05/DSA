#include <bits/stdc++.h>
using namespace std;

int minNumberOfdays(int n, int k, vector<int> &viRatings)
{
    vector<int> problems(n);
    for (int i = 0; i < n; i++)
    {
        problems[i] = i + 1;
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < problems.size(); i++)
    {
        int problem = problems[i];
        int vi = viRatings[i];
        mp[problem] = vi;
    }

    vector<bool> vis(n, false);

    int problemSolved = 0;

    int days = 0;

    for (int i = 0; i < problems.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            problemSolved++;
            int curProb = problems[i];
            int curVi = mp[curProb];
            for (int j = i + 1; j < problems.size(); j++)
            {
                if (!vis[j])
                {
                    int nextProb = problems[j];
                    int nextVi = mp[nextProb];
                    if (abs(nextVi - curVi) >= k)
                    {
                        vis[j] = true;
                        problemSolved++;
                    }
                }
            }
            days++;
        }
    }
    return days;
}

int main()
{
    int n = 5;
    int k = 1;

    vector<int> vi = {5, 3, 4, 5, 6};

    int ans = minNumberOfdays(n, k, vi);
    cout << "ans----->" << ans << endl;
    return 0;
}