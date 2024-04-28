#include <bits/stdc++.h>
using namespace std;

bool canplace_hori(char **a, int i, int j, string word)
{
    if (j - 1 >= 0 and a[i][j - 1] != '+')
    {
        return false;
    }

    if (j + word.length() <= 9 and a[i][j + word.length()] != '+')
    {
        return false;
    }

    for (int jj = 0; jj < word.length(); jj++)
    {
        if (j + jj > 9)
        {
            return false;
        }

        if (a[i][j + jj] == '-' or a[i][j + jj] == word[jj])
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

bool canplace_verti(char **a, int i, int j, string word)
{
    if (i - 1 >= 0 and a[i - 1][j] != '+')
    {
        return false;
    }

    if (i + word.length() <= 9 and a[i + word.length()][j] != '+')
    {
        return false;
    }

    for (int ii = 0; ii < word.length(); ii++)
    {
        if (i + ii > 9)
        {
            return false;
        }

        if (a[i + ii][j] == '-' or a[i + ii][j] == word[ii])
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

bool *place_H(char **a, int i, int j, string word)
{
    bool *we_placed = new bool[word.length()]();

    for (int jj = 0; jj < word.length(); jj++)
    {
        if (a[i][j + jj] == '-')
        {
            a[i][j + jj] = word[jj];
            we_placed[jj] = true;
        }
    }
    return we_placed;
}

bool *place_V(char **a, int i, int j, string word)
{
    bool *we_placed = new bool[word.length()]();

    for (int ii = 0; ii < word.length(); ii++)
    {
        if (a[i + ii][j] == '-')
        {
            a[i + ii][j] = word[ii];
            we_placed[ii] = true;
        }
    }
    return we_placed;
}

void unplace_H(char **a, int i, int j, bool *we_placed, string word)
{
    for (int jj = 0; jj < word.length(); jj++)
    {
        if (we_placed[jj])
        {
            a[i][j + jj] = '-';
        }
    }
}

void unplace_V(char **a, int i, int j, bool *we_placed, string word)
{
    for (int ii = 0; ii < word.length(); ii++)
    {
        if (we_placed[ii])
        {
            a[i + ii][j] = '-';
        }
    }
}

void cross_word(char **a, string *s, int n, int vidx)
{
    if (vidx == n)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        return;
    }

    string word = s[vidx];
    // cout << word << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] == '-' or a[i][j] == word[0])
            {
                if (canplace_hori(a, i, j, word))
                {
                    bool *we_placed_h = place_H(a, i, j, word);
                    cross_word(a, s, n, vidx + 1);
                    unplace_H(a, i, j, we_placed_h, word);
                }

                if (canplace_verti(a, i, j, word))
                {
                    bool *we_placed_v = place_V(a, i, j, word);
                    cross_word(a, s, n, vidx + 1);
                    unplace_V(a, i, j, we_placed_v, word);
                }
            }
        }
    }
}

int main()
{

    char **a = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = new char[10];
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> a[i][j];
        }
    }

    int n;
    cin >> n;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    cross_word(a, s, n, 0);
}

/*for (int i = 0; i <= n; i++)
{
    for (int j = 0; j <= n; j++)
    {
        cout << dp[i][j] << " ";
    }
    cout << endl;
}*/
// cout << maxi;