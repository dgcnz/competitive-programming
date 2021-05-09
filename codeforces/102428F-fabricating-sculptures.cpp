#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)

using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int solve(int s, int b)
{
    b -= s;
    vector<vector<mint>> dp(s + 1, vector<mint>(b + 1, 0));
    dp[0][0] = 1;
    fill(all(dp[1]), 1);
    for (int i = 2; i <= s; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            dp[i][j] = 2 * dp[i - 1][j] - dp[i - 2][j];
            if (j - i >= 0)
                dp[i][j] += dp[i][j - i];
        }
    }
    return dp[s][b].val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int s, b;
    cin >> s >> b;
    cout << solve(s, b) << endl;
    return 0;
}
