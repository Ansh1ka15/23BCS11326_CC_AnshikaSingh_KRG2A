#include <bits/stdc++.h>
using namespace std;
int countSetBits(int x)
{
    int count = 0;
    while (x > 0)
    {
        x = x & (x - 1); // remove last set bit, we could use stl -> __builtin_popcount() as well
        count++;
    }
    return count;
}

int solve(vector<int> &A)
{
    const int MOD = 1e9 + 7;
    long long ans = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int xorval = A[i] ^ A[j]; // XOR
            ans += countSetBits(xorval);
        }
    }
    return ans % MOD;
}
int main()
{
    vector<int> A = {1, 3, 5};
    cout << solve(A) << endl;
}
