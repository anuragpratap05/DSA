#include <bits/stdc++.h>
#include <cassert>
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

void displayBoard(vector<vector<char>> &board)
{
    for (vector<char> &vec : board)
    {
        for (char ch : vec)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

bool solveSudokuHelper(vector<vector<char>> &board, vector<int> &idxs, int box)
{
    if (box == idxs.size())
    {
        displayBoard(board);
        return true;
    }
    int n = board.size();
    int m = board[0].size();

    int idx = idxs[box];
    int i = idx / m;
    int j = idx % m;
    for (int num = 1; num <= 9; num++)
    {
        if (canNumBePlaced(i, j, num))
        {
            char myCh = num + '0';
            board[i][j] = myCh;
            row[i] ^= (1 << num);
            col[j] ^= (1 << num);
            mat[i / 3][j / 3] ^= (1 << num);
            bool ans = solveSudokuHelper(board, idxs, box + 1);
            if (ans)
            {
                return true;
            }
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
    row.resize(9, 0);
    col.resize(9, 0);
    mat.resize(3, vector<int>(3, 0));
    vector<int> idxs;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != '.')
            {
                char ch = board[i][j];
                int x = ch - '0';
                row[i] ^= (1 << x);
                col[j] ^= (1 << x);
                int r = i / 3;
                int c = j / 3;
                mat[r][c] ^= (1 << x);
            }
            else
            {
                idxs.push_back((i * m) + j);
            }
        }
    }
    solveSudokuHelper(board, idxs, 0);
}

int main()
{

    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);
    // int x = 9;
    // char ch = x + '0';
    // string str = "abc";
    // str += ch;
    // cout << str;

    // char ch = '9';
    // int x = ch - '0';
    // cout << x << endl;

    // cout << x + 1;
    return 0;
}