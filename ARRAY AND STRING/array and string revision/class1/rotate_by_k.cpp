#include <bits/stdc++.h>
using namespace std;

void rotate_by_k(vector<int> &vec, int k)
{
    int n = vec.size();
    k = k % n;
    if (k < 0)
    {
        k = k + n;
    }

    reverse(vec.begin(), vec.end());
    for (int e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
    reverse(vec.begin() + (n - k), vec.end());
    for (int e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
    reverse(vec.begin(), vec.begin() + (n - k));
    for (int e : vec)
    {
        cout << e << " ";
    }
}

int main()
{
    vector<int> vec = {9, 7, 2, 8, 6, 3};
    rotate_by_k(vec, 4);
    return 0;
}