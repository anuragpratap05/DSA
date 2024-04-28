#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<bool>> &board, int r, int c)
{
    int n = board.size();
    int m = board[0].size();
    for (int j = 0; j < m; j++)
    {
        if (board[r][j] == true)
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][c] == true)
        {
            return false;
        }
    }

    // UL
    for (int i = r - 1, j = c - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j] == true)
        {
            return false;
        }
    }

    // DR
    for (int i = r + 1, j = c + 1; i < n and j < m; i++, j++)
    {
        if (board[i][j] == true)
        {
            return false;
        }
    }

    // UR
    for (int i = r - 1, j = c + 1; i >= 0 and j < m; i--, j++)
    {
        if (board[i][j] == true)
        {
            return false;
        }
    }

    // DL
    for (int i = r + 1, j = c - 1; i < n and j >= 0; i++, j--)
    {
        if (board[i][j] == true)
        {
            return false;
        }
    }
    return true;
}

int queen_combi_2d(vector<vector<bool>> &board, int tnq, int cb, string psf)
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
        if (is_safe(board, r, c))
        {
            board[r][c] = true;
            count += queen_combi_2d(board, tnq - 1, i + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
            board[r][c] = false;
        }
    }
    return count;
}

int queen_permu_2d(vector<vector<bool>> &board, int tnq, string psf)
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
        if (is_safe(board, r, c))
        {
            board[r][c] = true;
            count += queen_permu_2d(board, tnq - 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
            board[r][c] = false;
        }
    }
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
    if (is_safe(board, r, c))
    {
        board[r][c]=true;
        count += queen_combi_sub_2d(board, tnq, cq + 1, cb + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
        board[r][c] = false;
    }
    
    count += queen_combi_sub_2d(board, tnq, cq, cb + 1, psf);
    return count;
}

int main()
{
    vector<vector<bool>> nums(4, vector<bool>(4));
    cout << queen_combi_2d(nums, 4, 0, "");


    // cout << queen_permu_2d(nums, 4,  "");

    // vector<vector<bool>> nums(4, vector<bool>(4));
    // cout << queen_combi_sub_2d(nums, 4, 0,0, "");
    return 0;
}