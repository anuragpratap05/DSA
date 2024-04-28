#include <bits/stdc++.h>
using namespace std;
// int isSubstring(string infStr, string toFind)
// {
//     // Repeat infStr enough times to cover the length of toFind
//     std::string repeated_str = "";
//     while (repeated_str.length() < toFind.length())
//     {
//         repeated_str += infStr;
//     }

//     // Check if toFind is a substring of the repeated string
//     if (repeated_str.find(toFind) != std::string::npos)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int isSubstring(string infStr, string toFind)
{
    // Repeat infStr enough times to cover the length of toFind plus the length of infStr minus 1
    string repeated_str = "";
    while (repeated_str.length() < toFind.length() + infStr.length() - 1)
    {
        repeated_str += infStr;
    }

    // Check if toFind is a substring of the repeated string
    if (repeated_str.find(toFind) != string::npos)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string infStr = "abcd";
    string toFind = "abcdabcdabcdabcdakbc";
    int ans = isSubstring(infStr, toFind);
    cout << "ans-->" << ans << endl;

    // cout << "(" << result.first << ", " << result.second << ")\n";

    // result = countOccurrences("abcd", "abcde");
    // cout << "(" << result.first << ", " << result.second << ")\n";

    // result = countOccurrences("abcd", "bc");
    // cout << "(" << result.first << ", " << result.second << ")\n";

    // result = countOccurrences("abcd", "bcdab");
    // cout << "(" << result.first << ", " << result.second << ")\n";

    // result = countOccurrences("abcd", "dabcdab");
    // cout << "(" << result.first << ", " << result.second << ")\n";

    // result = countOccurrences("abcd", "abcz");
    // cout << "(" << result.first << ", " << result.second << ")\n";

    // result = countOccurrences("abcd", "cdabcde");
    // cout << "(" << result.first << ", " << result.second << ")\n";

    return 0;
}