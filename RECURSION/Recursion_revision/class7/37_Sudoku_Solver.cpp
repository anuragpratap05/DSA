#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<char>> &board)
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
// vector<int> rows{0, 0, 0, 0, 0, 0, 0, 0, 0};
// vector<int> cols{0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<int> rows(9, 0);
vector<int> cols(9, 0);
vector<vector<int>> mat(3, vector<int>(3, 0));
bool canPlaceNum(vector<vector<char>> &board, int i, int j, int num)
{
    // cout << i << "," << j << "->" << num << endl;

    for (int idx = 0; idx < 9; idx++)
    {
        if (board[i][idx] - '0' == num or board[idx][j] - '0' == num)
        {
            return false;
        }
    }

    int r = (i / 3) * 3;
    int c = (j / 3) * 3;

    for (int row = r; row < r + 3; row++)
    {
        for (int col = c; col < c + 3; col++)
        {
            if (board[row][col] - '0' == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool canPlaceNumBits(vector<vector<char>> &board, int i, int j, int num)
{
    int mask = (1 << num);

    if ((rows[i] & mask) == 0 and (cols[j] & mask) == 0 and (mat[i / 3][j / 3] & mask) == 0)
    {
        return true;
    }

    return false;
}
bool solveSudokuHelper(vector<vector<char>> &board, int n, int box)
{
    if (box == n * n)
    {
        return true;
    }
    int r = box / 9;
    int c = box % 9;

    if (board[r][c] == '.')
    {

        for (int num = 1; num <= 9; num++)
        {
            int mask = (1 << num);
            if ((rows[r] & mask) == 0 and (cols[c] & mask) == 0 and (mat[r / 3][c / 3] & mask) == 0)
            {

                rows[r] ^= mask;
                cols[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
                board[r][c] = (char)(num + '0');
                bool ans = solveSudokuHelper(board, n, box + 1);
                if (ans)
                {
                    return true;
                }
                rows[r] ^= mask;
                cols[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
                board[r][c] = '.';
            }
        }
    }
    else
    {
        return solveSudokuHelper(board, n, box + 1);
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] != '.')
            {
                int num = board[r][c] - '0';
                int mask = (1 << num);
                rows[r] ^= mask;
                cols[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
            }
        }
    }
    bool ans = solveSudokuHelper(board, n, 0);
    if (ans)
    {
        cout << "mil gya ans" << endl;
    }
    display(board);
}

int main()
{

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    return 0;
}