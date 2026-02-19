#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    const int MOD = 1e9 + 7;
    long long ans = 0;
    int n = A.size();
    for(int bit = 0; bit < 32; bit++) {
        long long countSet = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] & (1 << bit)) {
                countSet++;
            }
        }
        long long countUnset = n - countSet;

        long long c = (2LL * countSet * countUnset) % MOD;
        ans = (ans + c) % MOD;
    }
    return ans;
}
int main() {
    vector<int> A = {1, 3, 5};
    cout << solve(A) << endl;
}
