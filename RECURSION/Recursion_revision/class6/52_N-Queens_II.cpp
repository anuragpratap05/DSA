#include <bits/stdc++.h>
using namespace std;
int rowsi = 0;
int colsi = 0;
int dia = 0;
int adia = 0;

bool isSafeToPlaceShadowBits(int n, int i, int j)
{

    if ((rowsi & (1 << i)) != 0 or (colsi & (1 << j)) != 0 or (dia & (1 << ((i - j) + n - 1))) != 0 or (adia & (1 << (i + j))) != 0)
    {
        return false;
    }
    return true;
}

int NQueenBits(int n, int m, int row)
{
    if (row == n)
    {

        return 1;
    }

    int c = 0;

    for (int col = 0; col < m; col++)
    {
        if (isSafeToPlaceShadowBits(n, row, col))
        {
            rowsi ^= (1 << row);
            colsi ^= (1 << col);
            dia ^= (1 << ((row - col) + n - 1));
            adia ^= (1 << (row + col));
            c += NQueenBits(n, m, row + 1);
            rowsi ^= (1 << row);
            colsi ^= (1 << col);
            dia ^= (1 << ((row - col) + n - 1));
            adia ^= (1 << (row + col));
        }
    }

    return c;
}
int totalNQueens(int n)
{
    return NQueenBits(n, n, 0);
}
int main()
{
    cout << totalNQueens(4);
    return 0;
}