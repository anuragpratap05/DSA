#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {-1, -1}, {0, -1}, {-1, 1}};                                   // for combi
vector<vector<int>> dirs = {{-1, 0}, {-1, -1}, {0, -1}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}}; // for permu

vector<int> rows;
vector<int> cols;
vector<int> diag;
vector<int> adiag;
int rowsi = 0;
int colsi = 0;
int dia = 0;
int adia = 0;
bool isSafeToPlace(vector<vector<bool>> &board, int i, int j)
{
    int n = board.size();
    for (vector<int> &vec : dir)
    {
        for (int jump = 1; jump < n; jump++)
        {
            int r = i + jump * vec[0];
            int c = j + jump * vec[1];
            if (r >= 0 and c >= 0 and r < n and c < n)
            {
                if (board[r][c])
                {
                    return false;
                }
            }
            else
            {
                break;
            }
        }
    }
    return true;
}

bool isSafeToPlaceShadow(int n, int i, int j)
{
    if (rows[i] or cols[j] or diag[(i - j) + n - 1] or adiag[i + j])
    {
        return false;
    }

    return true;
}

bool isSafeToPlaceShadowBits(int n, int i, int j)
{

    if ((rowsi & (1 << i)) != 0 or (colsi & (1 << j)) != 0 or (dia & (1 << ((i - j) + n - 1))) != 0 or (adia & (1 << (i + j))) != 0)
    {
        return false;
    }
    return true;
}

int queenCombi2DShadow(vector<vector<bool>> &boxes, int tnq, int cQun, int cBox, string psf)
{
    if (cQun > tnq)
    {
        cout << psf << endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();
    int c = 0;
    for (int bx = cBox; bx < n * m; bx++)
    {
        int row = bx / m;
        int col = bx % m;
        if (isSafeToPlaceShadow(n, row, col))
        {
            rows[row] = true;
            cols[col] = true;
            diag[(row - col) + n - 1] = true;
            adiag[row + col] = true;
            c += queenCombi2DShadow(boxes, tnq, cQun + 1, bx + 1, psf + "(" + to_string(row) + "," + to_string(col) + ") ");
            rows[row] = false;
            cols[col] = false;
            diag[(row - col) + n - 1] = false;
            adiag[row + col] = false;
        }
    }
    return c;
}
int numOfCalls = 0;
int NQueen(int n, int m, int row, string psf)
{
    if (row == n)
    {
        cout << psf << endl;
        return 1;
    }

    int c = 0;
    numOfCalls++;
    for (int col = 0; col < m; col++)
    {
        if (isSafeToPlaceShadow(n, row, col))
        {
            rows[row] = true;
            cols[col] = true;
            diag[(row - col) + n - 1] = true;
            adiag[row + col] = true;
            c += NQueen(n, m, row + 1, psf + "(" + to_string(row) + "," + to_string(col) + ") ");
            rows[row] = false;
            cols[col] = false;
            diag[(row - col) + n - 1] = false;
            adiag[row + col] = false;
        }
    }

    return c;
}

int NQueenBits(int n, int m, int row, string psf)
{
    if (row == n)
    {
        cout << psf << endl;
        return 1;
    }

    int c = 0;
    numOfCalls++;
    for (int col = 0; col < m; col++)
    {
        if (isSafeToPlaceShadowBits(n, row, col))
        {
            rowsi ^= (1 << row);
            colsi ^= (1 << col);
            dia ^= (1 << ((row - col) + n - 1));
            adia ^= (1 << (row + col));
            c += NQueenBits(n, m, row + 1, psf + "(" + to_string(row) + "," + to_string(col) + ") ");
            rowsi ^= (1 << row);
            colsi ^= (1 << col);
            dia ^= (1 << ((row - col) + n - 1));
            adia ^= (1 << (row + col));
        }
    }

    return c;
}

int queenCombi2D(vector<vector<bool>> &boxes, int tnq, int cQun, int cBox, string psf)
{
    if (cQun > tnq)
    {
        cout << psf << endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();
    int c = 0;
    for (int bx = cBox; bx < n * m; bx++)
    {
        int row = bx / m;
        int col = bx % m;
        if (isSafeToPlace(boxes, row, col))
        {
            boxes[row][col] = true;
            c += queenCombi2D(boxes, tnq, cQun + 1, bx + 1, psf + "(" + to_string(row) + "," + to_string(col) + ") ");
            boxes[row][col] = false;
        }
    }
    return c;
}

int queenPermu2D(vector<vector<bool>> &boxes, int tnq, int cQun, int cBox, string psf)
{
    if (cQun > tnq)
    {
        cout << psf << endl;
        return 1;
    }
    int n = boxes.size();
    int m = boxes[0].size();
    int c = 0;
    for (int bx = cBox; bx < n * m; bx++)
    {
        int row = bx / m;
        int col = bx % m;
        if (isSafeToPlace(boxes, row, col) and boxes[row][col] == false)
        {
            boxes[row][col] = true;
            c += queenPermu2D(boxes, tnq, cQun + 1, 0, psf + "(" + to_string(row) + "," + to_string(col) + ") ");
            boxes[row][col] = false;
        }
    }
    return c;
}
int main()
{
    int tnq = 3;
    int n = 4;
    int m = 4;
    rows.resize(n, false);
    cols.resize(m, false);

    diag.resize((2 * n) - 1, false);
    adiag.resize((2 * n) - 1, false);
    // vector<vector<bool>> board(n, vector<bool>(m, false));
    // cout << queenCombi2DShadow(board, tnq, 0, 0, "");
    cout << NQueenBits(n, m, 0, "") << endl;

    // cout << queenCombi2D(board, tnq, 0, 0, "");
    // cout << queenPermu2D(board, tnq, 0, 0, "");
    return 0;
}