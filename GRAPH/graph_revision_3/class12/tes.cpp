#include <bits/stdc++.h>
using namespace std;

void func()
{
    vector<int> vec(12, -1);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = i * 2;
        cout << vec[i] << " ";
    }
    vec.clear();
    vec.resize(12, -1);
    cout << endl;
    cout << vec.size() << endl;
    for (int e : vec)
    {
        cout << e << " ";
    }
}

int main()
{
    func();
    return 0;
}