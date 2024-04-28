#include <bits/stdc++.h>
using namespace std;

vector<bool> row;
vector<bool> col;
vector<bool> diag;
vector<bool> adiag;

bool isSafeToPlace(int r, int c, int n)
{
    if (row[r] or col[c] or diag[(n - 1) - (r - c)] or adiag[r + c])
    {
        return false;
    }
    return true;
}

int nQueenHelper(int n, int r, string psf)
{
    if (r == n)
    {
        cout << psf << endl;
        return 1;
    }
    int cnt = 0;
    for (int c = 0; c < n; c++)
    {
        if (isSafeToPlace(r, c, n))
        {
            
            row[r] = true;
            col[c] = true;
            diag[(n - 1) - (r - c)] = true;
            adiag[r + c] = true;
            cnt += nQueenHelper(n, r + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = false;
            col[c] = false;
            diag[(n - 1) - (r - c)] = false;
            adiag[r + c] = false;
        }
    }
    return cnt;
}

int nQueen(int n)
{
    row.resize(n, false);
    col.resize(n, false);
    diag.resize(2 * n - 1, false);
    adiag.resize(2 * n - 1, false);
    return nQueenHelper(n, 0, "");
}

int main()
{
    cout << nQueen(4);
    return 0;
}