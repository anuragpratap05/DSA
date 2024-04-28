#include <bits/stdc++.h>
using namespace std;



int col = 0;
int diag = 0;
int adiag = 0;

int queen_combi_2d_btr(int n, int tnq, int r)
{
    if (tnq == 0)
    {
        return 1;
    }

    int count = 0;

    for (int c = 0; c < n; c++)
    {
        // int mask=(1<<c);
        if (!(col & (1 << c)) and !(diag & (1 << (r + c))) and !(adiag & (1 << ((r - c) + (n - 1)))))
        {
            col ^= (1 << c);
            diag ^= (1 << (r + c));
            adiag ^= (1 << ((r - c) + (n - 1)));
            count += queen_combi_2d_btr(n, tnq - 1, r + 1);
            col ^= (1 << c);
            diag ^= (1 << (r + c));
            adiag ^= (1 << ((r - c) + (n - 1)));
        }
    }

    return count;
}

int main()
{

    return queen_combi_2d_btr(n, 4, 0);
}