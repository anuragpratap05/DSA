#include <bits/stdc++.h>
using namespace std;

vector<int> row;
vector<int> col;
vector<int> diag;
vector<int> adiag;

bool isSafeToPlaceShadow(int r, int c, int m)
{

    if (row[r] or col[c] or diag[m - 1 - (r - c)] or adiag[r + c])
    {
        return false;
    }
    return true;
}

int calls = 0;

int nQueenHelperCombi(int n, string psf, int r)
{

    if (r == n)
    {
        cout << psf << endl;
        return 1;
    }
    calls++;
    int cnt = 0;
    for (int c = 0; c < n; c++)
    {

        if (isSafeToPlaceShadow(r, c, n))
        {

            col[c] = true;
            diag[n - 1 - (r - c)] = true;
            adiag[r + c] = true;
            cnt += nQueenHelperCombi(n, psf + "(" + to_string(r) + "," + to_string(c) + ") ", r + 1);
            col[c] = false;
            diag[n - 1 - (r - c)] = false;
            adiag[r + c] = false;
        }
    }
    return cnt;
}

int nQueenShadow(int n)
{

    row.resize(n, false);
    col.resize(n, false);
    diag.resize((n + n) - 1, false);
    adiag.resize((n + n) - 1, false);
    return nQueenHelperCombi(n, "", 0);
}

int main()
{
    cout << nQueenShadow(10) << endl;
    cout << "calls=" << calls;
    return 0;
}