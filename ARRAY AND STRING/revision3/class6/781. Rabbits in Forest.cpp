#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{
    vector<int> freq(1001, 0);
    for (int rabitNums : answers)
    {
        freq[rabitNums + 1]++;
    }
    int totalrabits = 0;
    for (int i = 1; i < freq.size(); i++)
    {
        int rabitFreq = freq[i];
        if (rabitFreq == 0)
            continue;

        int quo = rabitFreq / i;
        int rem = rabitFreq % i;
        totalrabits += (quo * i) + rem > 0 ? i : 0;
    }
    return totalrabits;
}

int main()
{
    return 0;
}