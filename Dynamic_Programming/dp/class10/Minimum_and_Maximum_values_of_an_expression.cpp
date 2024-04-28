#include <bits/stdc++.h>
using namespace std;

int minMaxValueOfExprMemo(vector<string> &str, int si, int ei)
{
    if (si == ei)
        return stoi(str[si]);
    int maxVal = -1e9;
    for (int cut = si + 1; cut < ei; cut++)
    {
        if (str[cut] == "+" or str[cut] == "*")
        {
            int left = minMaxValueOfExprMemo(str, si, cut - 1);
            int right = minMaxValueOfExprMemo(str, cut + 1, ei);
            maxVal = max(maxVal, str[cut] == "+" ? left + right : left * right);
        }
    }
    return maxVal;
}

int minMaxValueOfExpr(string exp)
{
    vector<string> vec;
    string tmp = "";

    for (char ch : exp)
    {
        if (ch == '+' or ch == '*')
        {
            vec.push_back(tmp);
            ch == '+' ? vec.push_back("+") : vec.push_back("*");
            tmp = "";
        }
        else
        {
            tmp += ch;
        }
    }
    vec.push_back(tmp);
    return minMaxValueOfExprMemo(vec, 0, vec.size() - 1);
}

int main()
{
    // string str = "12+5*7236+77*298";
    string str = "11+101*102";
    int ans = minMaxValueOfExpr(str);

    cout << "ans-->" << ans << endl;
    // minMaxValueOfExpr(str);
    return 0;
}
