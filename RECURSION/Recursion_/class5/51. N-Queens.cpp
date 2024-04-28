#include <bits/stdc++.h>
using namespace std;

vector<bool> row;
vector<bool> col;
vector<bool> diag;
vector<bool> adiag;

void prepare(vector<vector<char>> &mat, vector<vector<string>> &ans)
{
    vector<string>sa;
    for(auto & vec:mat)
    {
        string s = "";
        for(char ch:vec)
        {
            s+=ch;
        }
        sa.push_back(s);
    }
    ans.push_back(sa);
}

int queen_combi_2d_btr(int n, int tnq, int r, vector<vector<char>> &mat, vector<vector<string>> &ans)
{
    if (tnq == 0)
    {
        prepare(mat,ans);
        return 1;
    }

    int count = 0;

    for (int c = 0; c < n; c++)
    {
        if (!row[r] and !col[c] and !diag[r + c] and !adiag[(r - c) + (n - 1)])
        {
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + (n - 1)] = true;
            mat[r][c]='Q';
            count += queen_combi_2d_btr(n, tnq - 1, r + 1,mat,ans);
            mat[r][c] = '.';
            row[r] = col[c] = diag[r + c] = adiag[(r - c) + (n - 1)] = false;
        }
    }

    return count;
}

vector<vector<string>> solveNQueens(int n)
{
    row.resize(n, false);
    col.resize(n, false);
    diag.resize((n + n) - 1, false);
    adiag.resize((n + n) - 1, false);
    vector<vector<string>> ans;
    vector<string>sa;
    vector<vector<char>>mat(n,vector<char>(n,'.'));



    cout << queen_combi_2d_btr(n, n, 0,mat,ans);
    return ans;
}

int main()
{
    return 0;
}