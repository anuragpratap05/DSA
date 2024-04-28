#include <bits/stdc++.h>
using namespace std;

bool ispossible_toplace_H(vector<vector<char>> &borad, string word, int r, int c, vector<int> &vis)
{
    int n = borad.size();
    int m = borad[0].size();
    int len = word.length();
    if (len + c > m)
    {
        return false;
    }
    int i = 0;
    for (int j = c; j < len + c; j++)
    {
        if (borad[r][j] != '-' and borad[r][j] != word[i]) // word[j]
        {
            return false;
        }
        i++;
    }
    return true;
}
void place_H(vector<vector<char>> &borad, string word, int r, int c, vector<int> &vis, int idx)
{
    int len = word.length();
    int i = 0;
    for (int j = c; j < len + c; j++)
    {
        if (borad[r][j] == '-')
        {
            char ch = word[i];
            int val = ch - 'a';
            borad[r][j] = ch;
            vis[idx] ^= (1 << val);
        }
        i++;
    }
}

void unplace_H(vector<vector<char>> &borad, string word, int r, int c, vector<int> &vis, int idx)
{
    int len = word.length();
    int i = 0;
    for (int j = c; j < len + c; j++)
    {
        char ch = word[i];
        int val = ch - 'a';
        if (vis[idx] & (1 << val))
        {

            borad[r][j] = '-';
            vis[idx] ^= (1 << val);
        }
        i++;
    }
}

bool ispossible_toplace_V(vector<vector<char>> &borad, string word, int r, int c, vector<int> &vis)
{
    int n = borad.size();
    int m = borad[0].size();
    int len = word.length();
    if (len + r > n)
    {
        return false;
    }
    int j = 0;
    for (int i = r; i < len + r; i++)
    {
        if (borad[i][c] != '-' and borad[i][c] != word[j])
        {
            return false;
        }
        j++;
    }
    return true;
}
void place_V(vector<vector<char>> &borad, string word, int r, int c, vector<int> &vis, int idx)
{
    int len = word.length();
    int j = 0;
    for (int i = r; i < len + r; i++)
    {
        if (borad[i][c] == '-')
        {
            char ch = word[j];
            int val = ch - 'a';
            borad[i][c] = ch;
            vis[idx] ^= (1 << val);
        }
        j++;
    }
}

void unplace_V(vector<vector<char>> &borad, string word, int r, int c, vector<int> &vis, int idx)
{
    int len = word.length();
    int j = 0;
    for (int i = r; i < len + r; i++)
    {
        char ch = word[j];
        int val = ch - 'a';
        if (vis[idx] & (1 << val))
        {

            borad[i][c] = '-';
            vis[idx] ^= (1 << val);
        }
        j++;
    }
}

bool crossword(vector<vector<char>> &board, vector<string> &words, int idx, vector<int> &vis)
{
    int n = board.size();
    int m = board[0].size();
    if (idx == words.size())
    {
        for (auto &vec : board)
        {
            for (char ch : vec)
            {
                cout << ch << " ";
            }
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '-' or board[i][j] == words[idx][0])
            {
                if (ispossible_toplace_H(board, words[idx], i, j, vis))
                {
                    place_H(board, words[idx], i, j, vis, idx);
                    if (crossword(board, words, idx + 1, vis))
                    {
                        return true;
                    }
                    unplace_H(board, words[idx], i, j, vis, idx);
                }
                if (ispossible_toplace_V(board, words[idx], i, j, vis))
                {
                    place_V(board, words[idx], i, j, vis, idx);
                    if (crossword(board, words, idx + 1, vis))
                    {
                        return true;
                    }
                    unplace_V(board, words[idx], i, j, vis, idx);
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board(10, vector<char>(10));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }

    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
    }
  
    vector<int>vis(n,0);
    crossword(board, words, 0,vis);
    return 0;

    // vector<string> words = {"agra",
    //                         "norway",
    //                         "england",
    //                         "gwalior"};

    // vector<vector<char>> board =
    //     {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    //      {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    //      {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    //      {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    //      {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};
}