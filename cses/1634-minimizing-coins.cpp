#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

// @idea: dp(i, s) : minimum coins needed in coins[1..i] to get to s
// dp(i, s) = min(dp(i - 1, s), dp(i, s - ci) + 1)
//                  / skip coin    / take coin and stay

const int NMAX = 1e2 + 11;
const int INF  = 1e9;

int n, x, c[NMAX];

int solve(void)
{
    vvi dp(n + 1, vi(x + 1, INF));
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int s = 1; s <= x; ++s)
        {
            int &ans = dp[i][s];
            ans      = dp[i - 1][s];
            if (s - c[i - 1] >= 0)
                ans = min(ans, dp[i][s - c[i - 1]] + 1);
        }
    }

    return (dp[n][x] == INF ? -1 : dp[n][x]);
}

int main(void)
{
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> c[i];

    cout << solve() << endl;

    return 0;
}
