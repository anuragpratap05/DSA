#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 1}, {1, 0}};
vector<string> moves = {"H", "D", "V"};
vector<string> mazePathHvdReturnType(int sr, int sc, int er, int ec)
{
    if (sr == er and sc == ec)
    {
        return {""};
    }

    vector<string> myAns;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            vector<string> recAns = mazePathHvdReturnType(r, c, er, ec);
            for (string str : recAns)
            {
                myAns.push_back(moves[i] + str);
            }
        }
    }
    return myAns;
}

int mazePathHvdVoidType(int sr, int sc, int er, int ec, vector<string> &ans, string psf)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            cnt += mazePathHvdVoidType(r, c, er, ec, ans, psf + moves[i]);
        }
    }
    return cnt;
}

vector<string> mazePathHvdReturnTypeMultiJupms(int sr, int sc, int er, int ec)
{
    if (sr == er and sc == ec)
    {
        return {""};
    }

    vector<string> myAns;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        for (int jump = 1; jump <= max(er, ec); jump++)
        {

            int r = sr + jump * vec[0];
            int c = sc + jump * vec[1];

            if (r >= 0 and c >= 0 and r <= er and c <= ec)
            {
                vector<string> recAns = mazePathHvdReturnTypeMultiJupms(r, c, er, ec);
                for (string str : recAns)
                {
                    myAns.push_back(to_string(jump) + moves[i] + str);
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
int mazePathHvdVoidTypeMultipleJumps(int sr, int sc, int er, int ec, vector<string> &ans, string psf)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        for (int jump = 1; jump <= max(er, ec); jump++)
        {

            int r = sr + jump * vec[0];
            int c = sc + jump * vec[1];

            if (r >= 0 and c >= 0 and r <= er and c <= ec)
            {
                cnt += mazePathHvdVoidTypeMultipleJumps(r, c, er, ec, ans, psf + to_string(jump) + moves[i]);
            }
            else
            {
                break;
            }
        }
    }
    return cnt;
}

int floodFill(int sr, int sc, int er, int ec, vector<string> &ans, vector<vector<bool>> &vis, string psf, vector<vector<int>> &dir, vector<string> &dirs)
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
        if (r >= 0 and c >= 0 and r <= er and c <= ec and !vis[r][c])
        {
            cnt += floodFill(r, c, er, ec, ans, vis, psf + dirs[i], dir, dirs);
        }
    }
    vis[sr][sc] = false;
    return cnt;
}

int main()
{
    // vector<string> ans = mazePathHvdReturnType(0, 0, 2, 2);
    // cout << ans.size() << endl;
    // for (string str : ans)
    // {
    //     cout << str << endl;
    // }

    // vector<string> ans;
    // cout << mazePathHvdVoidType(0, 0, 2, 2, ans, "") << endl;
    // for (string str : ans)
    // {
    //     cout << str << " ";
    // }

    // vector<string> ans = mazePathHvdReturnTypeMultiJupms(0, 0, 2, 2);
    // cout << ans.size() << endl;
    // for (string str : ans)
    // {
    //     cout << str << " ";
    // }

    // vector<string> ans;
    // cout << mazePathHvdVoidTypeMultipleJumps(0, 0, 2, 2, ans, "") << endl;
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
