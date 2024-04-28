#include <bits/stdc++.h>
using namespace std;
void Display(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
bool canPlaceHorizontal(vector<vector<char>> &board, int i, int j, string word)
{
    for (int jj = 0; jj < word.length(); jj++)
    {
        if (j + jj > 9)
        {
            return false;
        }
        if (board[i][j + jj] == '-' or board[i][j + jj] == word[jj])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool canPlaceVertical(vector<vector<char>> &board, int i, int j, string word)
{

    for (int ii = 0; ii < word.length(); ii++)
    {
        if (i + ii > 9)
        {
            return false;
        }
        if (board[i + ii][j] == '-' or board[i + ii][j] == word[ii])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeHorizontal(vector<vector<char>> &board, int i, int j, string word)
{
    vector<bool> vis(26, false);
    for (int jj = 0; jj < word.length(); jj++)
    {
        char ch = word[jj];
        if (board[i][j + jj] == '-')
        {
            board[i][j + jj] = ch;
            vis[ch - 'a'] = true;
        }
    }
    return vis;
}

vector<bool> placeVertical(vector<vector<char>> &board, int i, int j, string word)
{
    vector<bool> vis(26, false);

    for (int ii = 0; ii < word.length(); ii++)
    {
        char ch = word[ii];
        if (board[i + ii][j] == '-')
        {
            board[i + ii][j] = ch;
            vis[ch - 'a'] = true;
        }
    }
    return vis;
}

void unPlaceHorizontal(vector<vector<char>> &board, int i, int j, string word, vector<bool> &vis)
{
    for (int jj = 0; jj < word.length(); jj++)
    {
        char ch = word[jj];
        if (vis[ch - 'a'])
        {
            board[i][j + jj] = '-';
        }
    }
}

void unPlaceVertical(vector<vector<char>> &board, int i, int j, string word, vector<bool> &vis)
{
    for (int ii = 0; ii < word.length(); ii++)
    {
        char ch = word[ii];
        if (vis[ch - 'a'])
        {
            board[i + ii][j] = '-';
        }
    }
}

bool crosswordPuzzle(vector<vector<char>> &board, int i, int j, vector<string> &words, int baseCnt, vector<bool> &vis)
{
    if (baseCnt == words.size())
    {
        cout << "aya" << endl;
        Display(board);
        return true;
    }
    int n = board.size();
    int m = board[0].size();

    for (int r = i; r < n; r++)
    {

        for (int c = 0; c < m; c++)
        {
            // if (r == 7 and c == 2)
            // {
            //     cout << "now we are at row 7 and col 2" << endl;
            // }
            if (board[r][c] != '+')
            {
                for (int idx = 0; idx < words.size(); idx++)
                {
                    if (!vis[idx])
                    {
                        string word = words[idx];
                        if (canPlaceHorizontal(board, r, c, word))
                        {
                            // cout << "hori  (" << r << "," << c << ") ->" << word << endl;
                            vis[idx] = true;
                            vector<bool> placbyMeH = placeHorizontal(board, r, c, word);
                            if (crosswordPuzzle(board, r, c, words, baseCnt + 1, vis))
                            {
                                return true;
                            }
                            unPlaceHorizontal(board, r, c, word, placbyMeH);
                            // cout << "unplacing hori->" + word << endl;
                            vis[idx] = false;
                        }
                        if (canPlaceVertical(board, r, c, word))
                        {
                            // cout << "verti  (" << r << "," << c << ") ->" << word << endl;
                            // cout << "before placing" << endl;
                            // Display(board);
                            vis[idx] = true;
                            vector<bool> placbyMeV = placeVertical(board, r, c, word);
                            // cout << "after placing" << endl;

                            // Display(board);

                            if (crosswordPuzzle(board, r, c, words, baseCnt + 1, vis))
                            {
                                return true;
                            }
                            // cout << "unplacing verti->" + word << endl;

                            unPlaceVertical(board, r, c, word, placbyMeV);
                            vis[idx] = false;
                        }
                    }
                }
            }
        }
    }
    return false;
}
void crossword(vector<vector<char>> &board, vector<string> &words)
{
    vector<bool> vis(words.size(), false);
    crosswordPuzzle(board, 0, 0, words, 0, vis);
}

int main()
{
    // vector<vector<char>> board =
    //     {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '-', '-', '-', '-', '+', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '+', '-', '-', '-', '-', '-', '-', '+', '+'},
    //      {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'}};

    // vector<string> words = {"ankara",
    //                         "delhi",
    //                         "iceland",
    //                         "london"};
    vector<string> words = {"agra",
                            "norway",
                            "england",
                            "gwalior"};

    vector<vector<char>> board =
        {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
         {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
         {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
         {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
         {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
         {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
         {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
         {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
         {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
         {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

    crossword(board, words);
    return 0;
}