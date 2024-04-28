#include <bits/stdc++.h>
using namespace std;

int queenCombi(int tnb, int tnq, int cQun, int cBox, string psf)
{
    if (cQun == tnq)
    {
        cout << psf << endl;
        return 1;
    }
    int c = 0;
    for (int bx = cBox; bx < tnb; bx++)
    {
        c += queenCombi(tnb, tnq, cQun + 1, bx + 1, psf + "b" + to_string(bx) + "q" + to_string(cQun));
    }
    return c;
}

int queenCombiSub(int tnb, int tnq, int cQun, int cBox, string psf)
{
    if (cQun == tnq or cBox == tnb)
    {
        if (cQun == tnq)
        {
            cout << psf << endl;
            return 1;
        }
        return 0;
    }
    int c = 0;

    c += queenCombiSub(tnb, tnq, cQun + 1, cBox + 1, psf + "b" + to_string(cBox) + "q" + to_string(cQun) + " ");
    c += queenCombiSub(tnb, tnq, cQun, cBox + 1, psf);
    return c;
}

int queenPermu(int tnb, int tnq, int cQun, string psf, vector<bool> &vis)
{
    if (cQun == tnq)
    {
        cout << psf << endl;
        return 1;
    }
    int c = 0;
    for (int bx = 0; bx < tnb; bx++)
    {
        if (!vis[bx])
        {
            vis[bx] = true;
            c += queenPermu(tnb, tnq, cQun + 1, psf + "b" + to_string(bx) + "q" + to_string(cQun), vis);
            vis[bx] = false;
        }
    }
    return c;
}

//==============================================================================

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
        c += queenCombi2D(boxes, tnq, cQun + 1, bx + 1, psf + "(" + to_string(row) + "," + to_string(col) + ") ");
    }
    return c;
}

int main()
{
    int tnb = 5;
    int tnq = 3;
    // cout << queenCombi(tnb, tnq, 0, 0, "");

    // cout << queenCombiSub(tnb, tnq, 0, 0, "");

    // vector<bool> vis(tnb, false);
    // cout << queenPermu(tnb, tnq, 0, "", vis);
    vector<vector<bool>> boxes(4, vector<bool>(4, false));
    cout << queenCombi2D(boxes, tnq, 0, 0, "");
    return 0;
}