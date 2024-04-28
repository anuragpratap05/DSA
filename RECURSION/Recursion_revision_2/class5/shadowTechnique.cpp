#include <bits/stdc++.h>
using namespace std;

vector<int> row;
vector<int> col;
vector<int> diag;
vector<int> adiag;

bool isSafeToPlaceShadow(vector<vector<bool>> &board, int r, int c)
{
    int n = board.size();
    int m = board[0].size();
    if (row[r] or col[c] or diag[m - 1 - (r - c)] or adiag[r + c])
    {
        return false;
    }
    return true;
}
int calls = 0;
int nQueenHelperCombi(vector<vector<bool>> &board, int tnq, string psf, int cBox)
{

    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }
    calls++;
    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    for (int i = cBox; i < n * m; i++)
    {
        int r = i / m;
        int c = i % m;
        if (isSafeToPlaceShadow(board, r, c))
        {
            row[r] = true;
            col[c] = true;
            diag[m - 1 - (r - c)] = true;
            adiag[r + c] = true;
            cnt += nQueenHelperCombi(board, tnq - 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ", i + 1);
            row[r] = false;
            col[c] = false;
            diag[m - 1 - (r - c)] = false;
            adiag[r + c] = false;
        }
    }
    return cnt;
}

int nQueenShadow(vector<vector<bool>> &board, int tnq)
{
    int n = board.size();
    int m = board[0].size();
    row.resize(n, false);
    col.resize(m, false);
    diag.resize((n + m) - 1, false);
    adiag.resize((n + m) - 1, false);
    return nQueenHelperCombi(board, tnq, "", 0);
}

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
        if (!board[r][c] and isSafeToPlaceShadow(board, r, c))
        {
            row[r] = true;
            col[c] = true;
            diag[m - 1 - (r - c)] = true;
            adiag[r + c] = true;
            cnt += nQueenHelperPermu(board, tnq - 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ", 0);
            row[r] = false;
            col[c] = false;
            diag[m - 1 - (r - c)] = false;
            adiag[r + c] = false;
        }
    }
    return cnt;
}

int nQueenShadowPermu(vector<vector<bool>> &board, int tnq)
{
    int n = board.size();
    int m = board[0].size();
    row.resize(n, false);
    col.resize(m, false);
    diag.resize((n + m) - 1, false);
    adiag.resize((n + m) - 1, false);
    return nQueenHelperPermu(board, tnq, "", 0);
}

int main()
{
    vector<vector<bool>> board(10, vector<bool>(10, false));
    cout << nQueenShadow(board, 10) << endl;
    cout << "calls=" << calls;
    return 0;
}