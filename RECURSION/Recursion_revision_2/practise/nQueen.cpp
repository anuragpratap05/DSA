#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int row, col, diag, aDiag;

bool isSafeToPlaceBits(int r, int c, int n)
{
    if ((row & (1 << r)) or (col & (1 << c)) or (diag & (1 << ((n - 1) - (r - c)))) or (aDiag & (1 << (r + c))))
    {
        return false;
    }

    return true;
}

bool isSafeToPlace(vector<vector<bool>> &board, int i, int j)
{
    int n = board.size(), m = board[0].size();

    for (vector<int> &vec : dirs)
    {
        for (int jump = 1; jump < max(n, m); jump++)
        {
            int r = i + jump * vec[0];
            int c = j + jump * vec[1];
            if (r >= 0 and c >= 0 and r < n and c < m)
            {
                if (board[r][c])
                {
                    return false;
                }
            }
            else
                break;
        }
    }

    return true;
}

void displayBoard(vector<vector<bool>> &board)
{
    for (vector<bool> &vec : board)
    {
        for (bool ele : vec)
        {
            if (ele)
                cout << " Q ";
            else
                cout << " _ ";
        }
        cout << endl;
    }
    cout << endl;
}

bool nQueenHelper(vector<vector<bool>> &board, int r)
{
    if (r == board.size())
    {
        displayBoard(board);
        return true;
    }

    for (int c = 0; c < board[0].size(); c++)
    {
        if (isSafeToPlace(board, r, c))
        {
            board[r][c] = true;
            bool ans = nQueenHelper(board, r + 1);
            if (ans)
                return true;
            board[r][c] = false;
        }
    }
    return false;
}

bool nQueenHelperBits(vector<vector<bool>> &board, int r)
{
    if (r == board.size())
    {
        displayBoard(board);
        return true;
    }

    for (int c = 0; c < board[0].size(); c++)
    {
        if (isSafeToPlaceBits(r, c, board.size()))
        {
            row ^= (1 << r);
            col ^= (1 << c);
            diag ^= (1 << ((board.size() - 1) - (r - c)));
            aDiag ^= (1 << (r + c));
            bool ans = nQueenHelperBits(board, r + 1);
            if (ans)
                return true;
            row ^= (1 << r);
            col ^= (1 << c);
            diag ^= (1 << ((board.size() - 1) - (r - c)));
            aDiag ^= (1 << (r + c));
        }
    }
    return false;
}

void solveNQueens(int n)
{
    vector<vector<bool>> board(n, vector<bool>(n, false));
    // nQueenHelper(board, 0);
    nQueenHelperBits(board, 0);
}

int main()
{
    solveNQueens(4);
    return 0;
}