#include <bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<char>> &board, int r, int c, int num)
{
    for (int j = 0; j < 9; j++)
    {
        if (board[r][j] - '0' == num)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] - '0' == num)
        {
            return false;
        }
    }
    int nr = (r / 3) * 3;
    int nc = (c / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[nr + i][nc + j] - '0' == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku_help(vector<vector<char>> &board, int box)
{
    if (box == 9 * 9)
    {
        return true;
    }

    int r = box / 9;
    int c = box % 9;
    if (board[r][c] != '.')
    {
        return solveSudoku_help(board, box + 1);
    }
    for (int num = 1; num <= 9; num++)
    {

        if (is_safe(board, r, c, num))
        {
            // cout<<r<<" "<<c<<" "<<num<<endl;
            board[r][c] = (char)(num + '0');
            bool ans = solveSudoku_help(board, box + 1);
            if (ans)
            {
                return true;
            }
            board[r][c] = '.';
        }
    }

    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    solveSudoku_help(board, 0);
}


//+++++++++++===============+++++++++++++++++++++++=========+++++++++++=======++++++++++=======+++++++++++=



vector<int> rows{0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<int> cols{0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<vector<int>> mat{3, vector<int>(3, 0)};
bool solveSudoku_help_btr(vector<vector<char>> &board, int box)
{
    if (box == 9 * 9)
    {
        return true;
    }

    int r = box / 9;
    int c = box % 9;
    if (board[r][c] != '.')
    {

        return solveSudoku_help_btr(board, box + 1);
    }
    for (int num = 1; num <= 9; num++)
    {

        int mask = (1 << num);
        if ((rows[r] & mask) == 0 and (cols[c] & mask) == 0 and (mat[r / 3][c / 3] & mask) == 0)
        {

            rows[r] ^= mask;
            cols[c] ^= mask;
            mat[r / 3][c / 3] ^= mask;

            board[r][c] = (char)(num + '0');
            bool f = solveSudoku_help_btr(board, box + 1);
            if (f)
            {
                return true;
            }
            board[r][c] = '.';
            rows[r] ^= mask;
            cols[c] ^= mask;
            mat[r / 3][c / 3] ^= mask;
        }
    }

    return false;
}
void solveSudoku(vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int mask = 1 << (board[i][j] - '0');
                rows[i] ^= mask;
                cols[j] ^= mask;
                mat[i / 3][j / 3] ^= mask;
            }
        }
    }
    solveSudoku_help_btr(board, 0);
}

int main()
{

    // vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // solveSudoku_help(board, 0);
    // for (auto &vec : board)
    // {
    //     for (char ch : vec)
    //     {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}