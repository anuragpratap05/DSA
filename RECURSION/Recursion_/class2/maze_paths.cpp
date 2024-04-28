#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {
    {0, 1},
    {1, 1},
    {1, 0},
};
vector<string> moves = {"H", "D", "V"};
// return type or top to bottom approach
vector<string> mazePath_HVD(int sr, int sc, int er, int ec)
{
    if (sr == er and sc == ec)
    {
        vector<string> base = {""};
        return base;
    }
    vector<string> myans;
    for (int i = dir.size() - 1; i >= 0; i--)
    {
        int r = sr + dir[i][0];
        int c = sc + dir[i][1];
        if (r <= er and c <= ec)
        {
            vector<string> sa = mazePath_HVD(r, c, er, ec);

            for (auto str : sa)
            {
                myans.push_back(str + moves[i]);
            }
        }
    }
    return myans;
}

// void  type or bottom to top   approach
int maze_path_HVD(int sr, int sc, int er, int ec, vector<string> &ans, string str)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(str);
        return 1;
    }
    int count = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        int r = sr + dir[i][0];
        int c = sc + dir[i][1];
        if (r <= er and c <= ec)
        {
            count += maze_path_HVD(r, c, er, ec, ans, str + moves[i]);
        }
    }
    return count;
}

// return type or top to bottom approach
vector<string> maze_path_HVD_multi(int sr, int sc, int er, int ec)
{
    if (sr == er and sc == ec)
    {
        vector<string> base = {""};
        return base;
    }
    int maxi = max(er, ec);
    vector<string> myans;
    for (int i = dir.size() - 1; i >= 0; i--)
    {
        for (int jump = 1; jump <= maxi; jump++)
        {
            int r = sr + (jump * dir[i][0]);
            int c = sc + (jump * dir[i][1]);
            if (r <= er and c <= ec)
            {
                vector<string> sa = maze_path_HVD_multi(r, c, er, ec);

                for (auto str : sa)
                {
                    myans.push_back(str + moves[i] + to_string(jump));
                }
            }
        }
    }
    return myans;
}

// void  type or bottom to top   approach
int maze_path_HVD_multi(int sr, int sc, int er, int ec, vector<string> &ans, string str)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(str);
        return 1;
    }
    int count = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        for (int jump = 1; jump <= max(er, ec); jump++)
        {
            int r = sr + (jump * dir[i][0]);
            int c = sc + (jump * dir[i][1]);
            if (r <= er and c <= ec)
            {
                count += maze_path_HVD_multi(r, c, er, ec, ans, str + moves[i] + to_string(jump));
            }
        }
    }
    return count;
}

vector<vector<int>> dir1 = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> moves1 = {"U", "R", "D", "L"};
int floodfill(int sr, int sc, int er, int ec, vector<vector<bool>> &vis, vector<string> &ans, string psf)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }
    int count = 0;
    vis[sr][sc] = true;
    for (int i = 0; i < dir1.size(); i++)
    {
        int r = sr + dir1[i][0];
        int c = sc + dir1[i][1];
        if (r <= er and c <= ec and r >= 0 and c >= 0 and !vis[r][c])
        {
            
            count += floodfill(r, c, er, ec, vis, ans, psf + moves1[i]);
        }
    }
    vis[sr][sc] = false;
    return count;
}



int main()
{
    // vector<string> myans = mazePath_HVD(0, 0, 2, 2);
    // cout << myans.size() << endl;
    // for (auto ch : myans)
    // {
    //     cout << ch << " ";
    // }

    // vector<string> myans;
    // cout<<maze_path_HVD(0, 0, 2, 2, myans, "")<<endl;
    // for(auto ch:myans)
    // {
    //     cout<<ch<<" ";
    // }

    // vector<string> myans = maze_path_HVD_multi(0, 0, 2, 2);
    // cout << myans.size() << endl;
    // for (auto ch : myans)
    // {
    //     cout << ch << " ";
    // }

    // vector<string> myans;
    // cout << maze_path_HVD_multi(0, 0, 2, 2, myans, "") << endl;
    // for(auto ch:myans)
    // {
    //     cout<<ch<<" ";
    // }

    vector<string> vec;
    vector<vector<bool>>vis(3,vector<bool>(3,false));
    cout<<floodfill(0, 0, 2, 2,vis, vec, "")<<endl;
    for(auto str:vec)
    {
        cout<<str<<" ";
    }
    return 0;
}