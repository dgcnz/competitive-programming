#include <iostream>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int solve(int n)
{
    ll ans = 1;
    for (int i = 0; i < n; ++i)
        ans = (ans * 2) % MOD;

    return ans;
}

int main(void)
{
    int n;
    cin >> n;

    cout << solve(n) << endl;
    return 0;
}
