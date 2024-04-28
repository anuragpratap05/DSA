#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int True = 0, False = 0;
    Pair(int True, int False)
    {
        this->True = True;
        this->False = False;
    }
};

Pair getMyAns(Pair &left, Pair &right, char op)
{
    Pair myAns(0, 0);
    if (op == '|')
    {
        myAns.True += (left.True * right.True);
        myAns.True += (left.True * right.False);
        myAns.True += (left.False * right.True);
        myAns.False += (left.False * right.False);
    }
    else if (op == '&')
    {
        myAns.True += (left.True * right.True);
        myAns.False += (left.True * right.False);
        myAns.False += (left.False * right.True);
        myAns.False += (left.False * right.False);
    }
    else
    {
        myAns.True += (left.True * right.False);
        myAns.True += (left.False * right.True);

        myAns.False += (left.True * right.True);
        myAns.False += (left.False * right.False);
    }
    return myAns;
}

Pair countWaysMemo(int N, string &S, int si, int ei, vector<vector<Pair>> &dp)
{
    if (si == ei)
    {
        // Pair base;
        if (S[si] == 'T')
            return dp[si][ei] = Pair(1, 0);
        else
            return dp[si][ei] = Pair(0, 1);
    }

    if (dp[si][ei].True != -1 and dp[si][ei].False != -1)
        return dp[si][ei];

    Pair myAns(0, 0);

    for (int cut = si + 1; cut < ei; cut += 2)
    {
        Pair left = countWaysMemo(N, S, si, cut - 1, dp);
        Pair right = countWaysMemo(N, S, cut + 1, ei, dp);
        Pair recAns = getMyAns(left, right, S[cut]);

        myAns.True += recAns.True;
        myAns.True %= 1003;
        myAns.False += recAns.False;
        myAns.False %= 1003;
    }
    return dp[si][ei] = myAns;
}

int countWays(int N, string S)
{
    int n = S.size();
    vector<vector<Pair>> dp(n, vector<Pair>(n, Pair(-1, -1)));
    Pair p = countWaysMemo(N, S, 0, n - 1, dp);
    cout << "p.True--> " << p.True << endl;
    cout << "p.False--> " << p.False << endl;
    return p.True;
}

int main()
{
    string S = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    countWays(S.size(), S);
    // bool ans = false ^ true;
    // if (ans)
    //     cout << "TRUE";
    // else
    //     cout << "FALSE";
    // return 0;
}