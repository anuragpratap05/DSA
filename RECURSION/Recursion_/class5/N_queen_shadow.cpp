#include <bits/stdc++.h>
using namespace std;

vector<bool> row;
vector<bool> col;
vector<bool> diag;
vector<bool> adiag;

int queen_combi_2d(int m, int n, int tnq, int cb, string psf)
{
    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }

    int count = 0;

    for (int i = cb; i < m * n; i++)
    {
        int r = i / m;
        int c = i % m;
        if (!row[r] and !col[c] and !diag[r + c] and !adiag[(r - c) + m])
        {
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + m] = true;
            count += queen_combi_2d(m, n, tnq - 1, i + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + m] = false;
        }
    }
    return count;
}

int queen_combi_2d_btr(int n, int tnq, int r, string psf)
{
    if (tnq == 0)
    {
        cout << psf << endl;
        return 1;
    }

    int count = 0;

    for (int c = 0; c < n; c++)
    {
        if (!row[r] and !col[c] and !diag[r + c] and !adiag[(r - c) + n])
        {
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + n] = true;
            count += queen_combi_2d_btr(n, tnq - 1, r + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + n] = false;
        }
    }

    return count;
}

int main()
{
    int m = 4, n = 4;
    row.resize(m, false);
    col.resize(m, false);
    diag.resize((m + n) - 1, false);
    adiag.resize((m + n) - 1, false);

    //cout << queen_combi_2d(m, n, 4, 0, "");

    cout << queen_combi_2d_btr(n,4,0,"");

    return 0;
}