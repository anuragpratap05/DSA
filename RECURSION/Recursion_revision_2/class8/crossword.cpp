#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<char>> &board)
{
    for (vector<char> &vec : board)
    {
        for (char ch : vec)
        {
            cout << ch;
        }
        cout << endl;
    }
}

bool canPlaceHorizontal(vector<vector<char>> &board, string wordToBePlaced, int sr, int sc)
{

    if (wordToBePlaced.size() + sc > board[0].size())
    {
        return false;
    }
    for (int col = sc; col < sc + wordToBePlaced.size(); col++)
    {
        char ch = wordToBePlaced[col - sc];
        if (board[sr][col] != '-')
        {
            if (board[sr][col] == '+')
            {
                return false;
            }
            else
            {
                if (board[sr][col] != ch)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<bool> placeHorizontal(vector<vector<char>> &board, string wordToBePlaced, int sr, int sc)
{
    vector<bool> vis(wordToBePlaced.size(), false);

    for (int col = sc; col < sc + wordToBePlaced.size(); col++)
    {
        if (board[sr][col] == '-')
        {
            char ch = wordToBePlaced[col - sc];
            // int idx = ch - 'a';
            vis[col - sc] = true;
            board[sr][col] = ch;
        }
    }
    return vis;
}

void unPlaceHorizontal(vector<vector<char>> &board, string wordToBePlaced, int sr, int sc, vector<bool> &vis)
{
    for (int col = sc; col < sc + wordToBePlaced.size(); col++)
    {
        char ch = wordToBePlaced[col - sc];
        // int idx = ch - 'a';
        if (vis[col - sc])
        {
            // vis[idx] = false; glti
            board[sr][col] = '-';
        }
    }
}

bool canPlaceVertical(vector<vector<char>> &board, string wordToBePlaced, int sr, int sc)
{
    if (wordToBePlaced.size() + sr > board.size())
    {
        return false;
    }
    for (int row = sr; row < sr + wordToBePlaced.size(); row++)
    {
        char ch = wordToBePlaced[row - sr];
        if (board[row][sc] != '-')
        {
            if (board[row][sc] == '+')
            {
                return false;
            }
            else
            {
                if (board[row][sc] != ch)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<bool> placeVertical(vector<vector<char>> &board, string wordToBePlaced, int sr, int sc)
{
    vector<bool> vis(wordToBePlaced.size(), false);

    for (int row = sr; row < sr + wordToBePlaced.size(); row++)
    {
        if (board[row][sc] == '-')
        {
            char ch = wordToBePlaced[row - sr];
            // int idx = ch - 'a';
            vis[row - sr] = true;
            board[row][sc] = ch;
        }
    }
    return vis;
}

void unPlaceVertical(vector<vector<char>> &board, string wordToBePlaced, int sr, int sc, vector<bool> &vis)
{
    for (int row = sr; row < sr + wordToBePlaced.size(); row++)
    {
        char ch = wordToBePlaced[row - sr];
        // int idx = ch - 'a';
        if (vis[row - sr])
        {
            // vis[idx] = false; glti
            board[row][sc] = '-';
        }
    }
}

bool crossword(vector<vector<char>> &board, vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        // cout << "aya" << endl;
        display(board);
        return true;
    }
    string currentWord = words[idx];

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-' or board[i][j] == currentWord[0])
            {
                if (canPlaceHorizontal(board, currentWord, i, j))
                {
                    vector<bool> vis = placeHorizontal(board, currentWord, i, j);
                    // cout << "placed " + currentWord << " horizontally at (" + to_string(i) + "," + to_string(j) << endl;
                    bool ans = crossword(board, words, idx + 1);
                    if (ans)
                    {
                        return true;
                    }
                    unPlaceHorizontal(board, currentWord, i, j, vis);
                    // cout << "unplaced " + currentWord << " horizontally from (" + to_string(i) + "," + to_string(j) << endl;
                }
                if (canPlaceVertical(board, currentWord, i, j))
                {
                    vector<bool> vis = placeVertical(board, currentWord, i, j);
                    // cout << "placed " + currentWord << " vertically at (" + to_string(i) + "," + to_string(j) << endl;
                    bool ans = crossword(board, words, idx + 1);
                    if (ans)
                    {
                        return true;
                    }
                    unPlaceVertical(board, currentWord, i, j, vis);
                    // cout << "unplaced " + currentWord << " vertically from (" + to_string(i) + "," + to_string(j) << endl;
                }
            }
        }
    }
    return false;
}

int main()
{

    // char ch = 'a';
    // int x = ch - 'a';
    // cout << x+5;
    // vector<vector<char>> board(10, vector<char>(10));

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cin >> board[i][j];
    //     }
    // }

    // int n;
    // cin >> n;
    // vector<string> words;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     words.push_back(s);
    // }
    // vector<int> vis(n, 0);

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

    // vector<vector<char>> board(10, vector<char>(10));

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         char ch;
    //         cin >> ch;
    //         board[i][j] = ch;
    //     }
    // }

    // int n;
    // cin >> n;
    // vector<string> words;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     words.push_back(s);
    // }



    crossword(board, words, 0);
    return 0;
}