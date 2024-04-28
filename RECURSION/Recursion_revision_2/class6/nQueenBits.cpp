#include <bits/stdc++.h>
using namespace std;

int row = 0;
int col = 0;
int diag = 0;
int adiag = 0;

bool isSafeToPlace(int r, int c, int n)
{
    if ((row & (1 << r)) or (col & (1 << c)) or (diag & (1 << ((n - 1) - (r - c)))) or
        (adiag & (1 << (r + c))))
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

            row ^= (1 << r);
            col ^= (1 << c);
            diag ^= (1 << ((n - 1) - (r - c)));
            adiag ^= (1 << (r + c));
            cnt += nQueenHelper(n, r + 1, psf + "(" + to_string(r) + "," + to_string(c) + ") ");
            row ^= (1 << r);
            col ^= (1 << c);
            diag ^= (1 << ((n - 1) - (r - c)));
            adiag ^= (1 << (r + c));
        }
    }
    return cnt;
}

int nQueen(int n)
{
    return nQueenHelper(n, 0, "");
}

int main()
{
    cout << nQueen(4);
    return 0;
}