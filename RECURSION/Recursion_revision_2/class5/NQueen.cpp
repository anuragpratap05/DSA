#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
vector<vector<int>> dirsPermu = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
bool isSafeToPlace(vector<vector<bool>> &board, int i, int j)
{
    int n = board.size();
    int m = board[0].size();
    for (vector<int> &vec : dirsPermu)
    {
        for (int jump = 1; jump < max(n, m); jump++)
        {
            int r = i + jump * vec[0];
            int c = j + jump * vec[1];
            if (r >= 0 and c >= 0 and r < n and c < m)
            {
                if (board[r][c])
                {
                    return false;
                }
            }
            else
            {
                break;
            }
        }
    }
    return true;
}

int nQueenHelperCombi(vector<vector<bool>> &board, int tnq, string psf, int cBox)
{

    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    for (int i = cBox; i < n * m; i++)
    {
        int r = i / m;
        int c = i % m;
        if (isSafeToPlace(board, r, c))
        {
            board[r][c] = true;
            cnt += nQueenHelperCombi(board, tnq - 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ", i + 1);
            board[r][c] = false;
        }
    }
    return cnt;
}

int nQueenHelperCombiSub(vector<vector<bool>> &board, int tnq, int idx, string psf)
{
    int n = board.size();
    int m = board[0].size();
    if (tnq == 0 or idx == n * m)
    {
        if (tnq == 0)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }

    int cnt = 0;

    int r = idx / m;
    int c = idx % m;
    if (isSafeToPlace(board, r, c))
    {
        board[r][c] = true;
        cnt += nQueenHelperCombiSub(board, tnq - 1, idx + 1, psf + "(" + to_string(r) + "," + to_string(c) + ")" + " ");
        board[r][c] = false;
    }

    cnt += nQueenHelperCombiSub(board, tnq, idx + 1, psf);

    return cnt;
}
int nQueenCombi(vector<vector<bool>> &board, int tnq)
{
    return nQueenHelperCombi(board, tnq, "", 0);
    return nQueenHelperCombiSub(board, tnq, 0, "");
}

//++++++++++==============++++++++++++++++++++==================++++++++++++++++++======

int nQueenHelperPermu(vector<vector<bool>> &board, int tnq, string psf, int cBox)
{

    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    for (int i = cBox; i < n * m; i++)
    {
        int r = i / m;
        int c = i % m;
        if (!board[r][c] and isSafeToPlace(board, r, c))
        {
            board[r][c] = true;
            cnt += nQueenHelperPermu(board, tnq - 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ", 0);
            board[r][c] = false;
        }
    }
    return cnt;
}
int nQueenHelperPermuSub(vector<vector<bool>> &board, int tnq, int idx, string psf)
{
    int n = board.size();
    int m = board[0].size();
    if (tnq == 0 or idx == n * m)
    {
        if (tnq == 0)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }

    int cnt = 0;

    int r = idx / m;
    int c = idx % m;
    if (!board[r][c] and isSafeToPlace(board, r, c))
    {
        board[r][c] = true;
        cnt += nQueenHelperPermuSub(board, tnq - 1, 0, psf + "(" + to_string(r) + "," + to_string(c) + ")" + " ");
        board[r][c] = false;
    }
    cnt += nQueenHelperPermuSub(board, tnq, idx + 1, psf);
    // cout << r << "  " << c << ",   ";

    return cnt;
}
int nQueenPermu(vector<vector<bool>> &board, int tnq)
{
    // return nQueenHelperPermu(board, tnq, "", 0);
    return nQueenHelperPermuSub(board, tnq, 0, "");
}

int main()
{
    vector<vector<bool>> board(4, vector<bool>(4, false));
    int tnq = 4;
    cout << nQueenPermu(board, tnq);
    return 0;
}