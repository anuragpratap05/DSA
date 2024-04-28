#include <bits/stdc++.h>
using namespace std;
int queenCombiHelper(int tnb, int tnq, int cb, int cq, string psf)
{
    if (cq == tnq)
    {
        cout << psf << endl;
        return 1;
    }

    int cnt = 0;
    for (int b = cb; b < tnb; b++)
    {
        cnt += queenCombiHelper(tnb, tnq, b + 1, cq + 1, psf + "b" + to_string(b) + "q" + to_string(cq) + " ");
    }
    return cnt;
}

int queenCombiSub(int tnb, int tnq, int cb, int cq, string psf)
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

    int cnt = 0;
    cnt += queenCombiSub(tnb, tnq, cb + 1, cq + 1, psf + "b" + to_string(cb) + "q" + to_string(cq) + " ");

    cnt += queenCombiSub(tnb, tnq, cb + 1, cq, psf);
    return cnt;
}

int queenCombination(int tnb, int tnq)
{
    // return queenCombiSub(tnb, tnq, 0, 0, "");
    return queenCombiHelper(tnb, tnq, 0, 0, "");
}

//++++++++++++++++===============++++++++++++++++================+++++++++++++===================

int queenCombi2DHelper(vector<vector<bool>> &board, int tnq, int idx, string psf)
{
    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }

    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    for (int b = idx; b < n * m; b++)
    {
        int r = b / m;
        int c = b % m;
        // cout << r << "  " << c << ",   ";
        cnt += queenCombi2DHelper(board, tnq - 1, b + 1, psf + "(" + to_string(r) + "," + to_string(c) + ")" + " ");
    }
    return cnt;
}

int queenCombi2DSub(vector<vector<bool>> &board, int tnq, int idx, string psf)
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
    cnt += queenCombi2DSub(board, tnq - 1, idx + 1, psf + "(" + to_string(r) + "," + to_string(c) + ")" + " ");

    cnt += queenCombi2DSub(board, tnq, idx + 1, psf);

    return cnt;
}

int queenCombi2D(vector<vector<bool>> &board, int tnq)
{
    // return queenCombi2DHelper(board, tnq, 0, "");
    return queenCombi2DSub(board, tnq, 0, "");
}

//++++++++++++++++===============++++++++++++++++================+++++++++++++===================

int queenPermuHelper(int tnb, int tnq, int cq, string psf, vector<bool> &vis)
{
    if (cq == tnq)
    {
        cout << psf << endl;
        return 1;
    }

    int cnt = 0;
    for (int b = 0; b < tnb; b++)
    {
        if (!vis[b])
        {
            vis[b] = true;
            cnt += queenPermuHelper(tnb, tnq, cq + 1, psf + "b" + to_string(b) + "q" + to_string(cq) + " ", vis);
            vis[b] = false;
        }
    }
    return cnt;
}

int queenPermuSub(int tnb, int tnq, int cb, int cq, string psf, vector<bool> &vis)
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

    int cnt = 0;
    if (!vis[cb])
    {
        vis[cb] = true;
        cnt += queenPermuSub(tnb, tnq, 0, cq + 1, psf + "b" + to_string(cb) + "q" + to_string(cq) + " ", vis);
        vis[cb] = false;
    }
    cnt += queenPermuSub(tnb, tnq, cb + 1, cq, psf, vis);
    return cnt;
}

int queenPermu(int tnb, int tnq)
{
    vector<bool> vis(tnb, false);
    // return queenPermuHelper(tnb, tnq, 0, "", vis);
    return queenPermuSub(tnb, tnq, 0, 0, "", vis);
}

//++++++++++++++++===============++++++++++++++++================+++++++++++++===================

int queenPermu2DHelper(vector<vector<bool>> &board, int tnq, int idx, string psf)
{
    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }

    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    for (int b = idx; b < n * m; b++)
    {
        int r = b / m;
        int c = b % m;
        if (!board[r][c])
        {
            board[r][c] = true;
            cnt += queenPermu2DHelper(board, tnq - 1, 0, psf + "(" + to_string(r) + "," + to_string(c) + ")" + " ");

            board[r][c] = false;
        }
        // cout << r << "  " << c << ",   ";
    }
    return cnt;
}

int queenPermu2DSub(vector<vector<bool>> &board, int tnq, int idx, string psf)
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
    if (!board[r][c])
    {
        board[r][c] = true;
        cnt += queenPermu2DSub(board, tnq - 1, 0, psf + "(" + to_string(r) + "," + to_string(c) + ")" + " ");
        board[r][c] = false;
    }
    cnt += queenPermu2DSub(board, tnq , idx + 1, psf);
    // cout << r << "  " << c << ",   ";

    return cnt;
}

int queenPermu2D(vector<vector<bool>> &board, int tnq)
{
    return queenPermu2DHelper(board, tnq, 0, "");
    return queenPermu2DSub(board, tnq, 0, "");
}

int main()
{
    // cout << queenCombination(5, 3);
    // cout << queenPermu(5, 3);

    vector<vector<bool>> board(4, vector<bool>(4, false));
    cout << queenCombi2D(board, 4);
    cout << queenPermu2D(board, 4);
    return 0;
}