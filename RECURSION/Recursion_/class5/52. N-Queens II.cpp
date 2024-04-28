#include<bits/stdc++.h>
using namespace std;

vector<bool> row;
vector<bool> col;
vector<bool> diag;
vector<bool> adiag;

int queen_combi_2d_btr(int n, int tnq, int r)
{
    if (tnq == 0)
    {
        return 1;
    }

    int count = 0;

    for (int c = 0; c < n; c++)
    {
        if (!row[r] and !col[c] and !diag[r + c] and !adiag[(r - c) + (n - 1)])
        {
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + (n - 1)] = true;
            count += queen_combi_2d_btr(n, tnq - 1, r + 1);
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + (n - 1)] = false;
        }
    }

    return count;
}
int totalNQueens(int n)
{
    
    row.resize(n, false);
    col.resize(n, false);
    diag.resize((n + n) - 1, false);
    adiag.resize((n + n) - 1, false);

    

    return queen_combi_2d_btr(n, 4, 0);
}

int main()
{
    return 0;
}