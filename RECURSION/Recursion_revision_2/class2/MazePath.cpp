#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0, 1}, {1, 1}, {1, 0}};
vector<string> movements = {"H", "D", "V"};

vector<string> mazePathReturnType(int sr, int sc, int er, int ec)
{
    if (sr == er and sc == ec)
    {
        return {""};
    }

    vector<string> myans;
    for (int i = 0; i < dirs.size(); i++)
    {
        vector<int> &vec = dirs[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            vector<string> recAns = mazePathReturnType(r, c, er, ec);
            for (string str : recAns)
            {
                myans.push_back(movements[i] + str);
            }
        }
    }
    return myans;
}

int mazePathVoidType(int sr, int sc, int er, int ec, vector<string> &ans, string psf)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }

    int cnt = 0;
    for (int i = 0; i < dirs.size(); i++)
    {
        vector<int> &vec = dirs[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            cnt += mazePathVoidType(r, c, er, ec, ans, psf + movements[i]);
        }
    }
    return cnt;
}

vector<string> mazePathReturnTypeMulti(int sr, int sc, int er, int ec)
{

    if (sr == er and sc == ec)
    {
        return {""};
    }
    vector<string> myAns;
    for (int i = 0; i < dirs.size(); i++)
    {
        vector<int> &vec = dirs[i];
        for (int jump = 1; jump <= max(er, ec); jump++)
        {
            int r = sr + jump * vec[0];
            int c = sc + jump * vec[1];
            if (r >= 0 and c >= 0 and r <= er and c <= ec)
            {
                vector<string> recAns = mazePathReturnTypeMulti(r, c, er, ec);
                for (string str : recAns)
                {
                    myAns.push_back(to_string(jump) + movements[i] + str);
                }
            }
            else
            {
                break;
            }
        }
    }
    return myAns;
}

int mazePathVoidTypeMulti(int sr, int sc, int er, int ec, vector<string> &ans, string psf)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < dirs.size(); i++)
    {
        vector<int> &vec = dirs[i];
        for (int jump = 1; jump <= max(er, ec); jump++)
        {
            int r = sr + jump * vec[0];
            int c = sc + jump * vec[1];
            if (r >= 0 and c >= 0 and r <= er and c <= ec)
            {
                cnt += mazePathVoidTypeMulti(r, c, er, ec, ans, psf + to_string(jump) + movements[i]);
            }
            else
            {
                break;
            }
        }
    }
    return cnt;
}

int floodFill(int sr, int sc, int er, int ec, vector<string> &ans, vector<vector<bool>> &vis, string psf, vector<vector<int>> &dir, vector<string> &movements)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }

    vis[sr][sc] = true;
    int cnt = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            if (!vis[r][c])
            {
                cnt += floodFill(r, c, er, ec, ans, vis, psf + movements[i], dir, movements);
            }
        }
        }
    vis[sr][sc] = false;
    return cnt;
}

int main()
{
    // vector<string> ans = mazePathReturnType(0, 0, 2, 2);
    // cout << ans.size() << endl;
    // for (string str : ans)
    // {
    //     cout << str << endl;
    // }

    // vector<string> ans;
    // cout << mazePathVoidType(0, 0, 2, 2, ans, "") << endl;
    // for (string str : ans)
    // {
    //     cout << str << " ";
    // }

    // vector<string> ans = mazePathReturnTypeMulti(0, 0, 2, 2);
    // cout << ans.size() << endl;
    // for (string str : ans)
    // {
    //     cout << str << " ";
    // }

    // vector<string> ans;
    // cout << mazePathVoidTypeMulti(0, 0, 2, 2, ans, "") << endl;
    // for (string str : ans)
    // {
    //     cout << str << " ";
    // }

    vector<vector<int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    vector<string> dirs = {"U", "E", "L", "S", "D", "N", "R", "W"};
    vector<vector<bool>> vis(3, vector<bool>(3, false));
    vector<string> ans;
    cout << floodFill(0, 0, 2, 2, ans, vis, "", dir, dirs) << endl;

    for (string str : ans)
    {
        cout << str << " ";
    }
    return 0;
}