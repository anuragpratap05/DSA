#include <bits/stdc++.h>
using namespace std;

vector<int> row;
vector<int> col;
vector<vector<int>> mat;

bool canNumBePlaced(int r, int c, int num)
{
    if ((row[r] & (1 << num)) or (col[c] & (1 << num)) or (mat[r / 3][c / 3] & (1 << num)))
    {
        return false;
    }
    return true;
}

bool solveSudokuHelper(vector<vector<char>> &board, vector<int> &indexes, int box)
{
    if (box == indexes.size())
    {
        return true;
    }

    int idx = indexes[box];
    int i = idx / board[0].size();
    int j = idx % board[0].size();

    for (int num = 1; num <= 9; num++)
    {
        if (canNumBePlaced(i, j, num))
        {
            row[i] ^= (1 << num);
            col[j] ^= (1 << num);
            mat[i / 3][j / 3] ^= (1 << num);
            board[i][j] = num + '0';
            bool ans = solveSudokuHelper(board, indexes, box + 1);
            if (ans)
                return true;
            row[i] ^= (1 << num);
            col[j] ^= (1 << num);
            mat[i / 3][j / 3] ^= (1 << num);
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<int> indexes;

    row.resize(9, 0);
    col.resize(9, 0);
    mat.resize(3, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '.')
            {
                indexes.push_back((i * m) + j);
            }
            else
            {
                int num = board[i][j] - '0';
                row[i] ^= (1 << num);
                col[j] ^= (1 << num);
                mat[i / 3][j / 3] ^= (1 << num);
            }
        }
    }
    solveSudokuHelper(board, indexes, 0);
}

int main()
{
    return 0;
}