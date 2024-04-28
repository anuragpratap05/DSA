#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    stack<char> st;
    vector<int> freq(26, 0);

    vector<bool> inStack(26, false);

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    for (char ch : s)
    {
        freq[ch - 'a']--;
        if (inStack[ch - 'a'])
            continue;

        while (!st.empty() and freq[st.top() - 'a'] > 0 and st.top() > ch)
        {
            inStack[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(ch);
        inStack[ch - 'a'] = true;
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << removeDuplicateLetters("cbadccbc");
    return 0;
}