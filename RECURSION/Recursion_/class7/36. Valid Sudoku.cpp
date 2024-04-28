#include<bits/stdc++.h>
using namespace std;

vector<int> rows{0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<int> cols{0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<vector<int>> mat{3, vector<int>(3, 0)};

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int mask = 1 << (board[i][j] - '0');
                if ((rows[i] & mask) == 0 and (cols[j] & mask) == 0 and (mat[i / 3][j / 3] & mask) == 0)
                {

                    rows[i] ^= mask;
                    cols[j] ^= mask;
                    mat[i/ 3][j / 3] ^= mask;

                    
                   
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    return 0;
}