#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using vi = vector<int>;

int solve(string s, string t)
{
    int        n = isz(s), m = isz(t);
    vector<vi> dp(n + 1, vi(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            auto &ans = dp[i][j];
            ans       = max(ans, dp[i - 1][j]);
            ans       = max(ans, dp[i][j - 1]);
            if (s[i - 1] == t[j - 1])
                ans = max(ans, dp[i - 1][j - 1] + 1);
        }
    }

    return dp[n][m];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s, t;
    while (getline(cin, s) and getline(cin, t))
    {
        cout << solve(s, t) << endl;
    }
    return 0;
}
