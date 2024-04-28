#include <bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N)
{
    int totalSum = 0;
    int firstSum = 0;

    for (int i = 0; i < N; i++)
    {
        totalSum += A[i];
        firstSum += (i * A[i]);
    }
    int ans = firstSum;
    for (int i = 1; i < N; i++)
    {
        int prev = A[i - 1];

        int curr = A[i];
        firstSum = ((firstSum - totalSum) + prev) + (prev * (N - 1));
        // cout << firstSum << endl;
        ans = max(ans, firstSum);
    }
    return ans;
}

int main()
{
    int myNumbers[4] = {8, 3, 1, 2};
    int N = 4;
    cout<<max_sum(myNumbers, N);

    return 0;
}