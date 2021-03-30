#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

ll solve(int n, int k)
{
    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));
    for (int hits = 0; hits <= n; ++hits)
        dp[hits][1] = 1;
    for (int age = 0; age <= k; ++age)
        dp[0][age] = 1;

    for (int age = 2; age <= k; ++age)
        for (int hits = 1; hits <= n; ++hits)
            dp[hits][age] = dp[hits - 1][age] + dp[n - hits][age - 1];
    return dp[n][k].val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}
