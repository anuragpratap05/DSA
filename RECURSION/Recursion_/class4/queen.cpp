          #include <bits/stdc++.h>
using namespace std;

int queencombi_1d(int tnb, int tnq, int cq, int cb, string psf)
{

    if (cq == tnq)
    {

        cout << psf << endl;
        return 1;
    }

    int count = 0;
    for (int i = cb; i < tnb; i++)
    {
        count += queencombi_1d(tnb, tnq, cq + 1, i + 1, psf + "q" + to_string(cq) + "b" + to_string(i) + " ");
    }
    return count;
}

int queen_permu_1d(int tnb, int tnq, int cq, string psf, vector<bool> &vis)
{
    if (cq == tnq)
    {

        cout << psf << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < tnb; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            count += queen_permu_1d(tnb, tnq, cq + 1, psf + "q" + to_string(cq) + "b" + to_string(i) + " ", vis);
            vis[i] = false;
        }
    }
    return count;
}

int queen_combi_2d(vector<vector<int>> &board, int tnq, int cb, string psf)
{
    if (tnq == 0)
    {

        cout << psf << endl;
        return 1;
    }

    int count = 0;
    int n = board.size();
    int m = board[0].size();
    for (int i = cb; i < m * n; i++)
    {
        int r = i / m;
        int c = i % m;
        count += queen_combi_2d(board, tnq - 1, i + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
    }
    return count;
}

int queen_permu_2d(vector<vector<int>> &board, int tnq, string psf, vector<vector<bool>> &vis)
{
    if (tnq == 0)
    {

        cout << psf << endl;
        return 1;
    }

    int count = 0;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < m * n; i++)
    {
        int r = i / m;
        int c = i % m;
        if (!vis[r][c])
        {
            vis[r][c] = true;
            count += queen_permu_2d(board, tnq - 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ", vis);
            vis[r][c] = false;
        }
    }
    return count;
}

int queen_combi_sub_1d(int tnb, int tnq, int cq, int cb, string psf)
{
    if (cq == tnq or cb == tnb)
    {
        if (cq == tnq)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    count += queen_combi_sub_1d(tnb, tnq, cq + 1, cb + 1, psf + "q" + to_string(cq) + "b" + to_string(cb) + " ");
    count += queen_combi_sub_1d(tnb, tnq, cq, cb + 1, psf);
    return count;
}

int queen_combi_sub_2d(vector<vector<bool>> &board, int tnq, int cq, int cb, string psf)
{
    int n = board.size();
    int m = board[0].size();
    if (cq == tnq or cb == n * m)
    {
        if (cq == tnq)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    int r = cb / m;
    int c = cb % m;
    count += queen_combi_sub_2d(board, tnq, cq + 1, cb + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
    count += queen_combi_sub_2d(board, tnq, cq, cb + 1, psf);
    return count;
}

int main()
{
    // cout << queencombi_1d(5, 3, 0, 0, "");
    // vector<bool> vis(5, false);
    // cout << queen_combi_sub_1d(5, 3, 0, 0, "");

    // vector<vector<bool>> board(4, vector<bool>(4));
    //  cout << queen_combi_sub_2d(nums, 4, 0,0, "");

    vector<vector<int>> board(4, vector<int>(4, false));

    cout << queen_combi_2d(board, 4, 0, "");

    // vector<vector<bool>> vis(4,vector<bool>(4,false));
    // cout<<queen_permu_2d(nums,4,"",vis);

    return 0;
}