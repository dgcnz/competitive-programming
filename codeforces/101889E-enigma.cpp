#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(string s, int n)
{
    int                 m   = s.size();
    int const           INF = 10;
    vector<vector<int>> dp(m + 1, vector<int>(n, INF));
    dp[m][0] = 0;
    vector<ll> pten(m);
    pten[m - 1] = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        if (i != m - 1)
            pten[i] = (10 * pten[i + 1]) % n;

        for (int r = 0; r < n; ++r)
        {
            if (s[i] != '?')
            {
                int   d   = s[i] - '0';
                auto &ans = dp[i][(r + pten[i] * d) % n];
                if (dp[i + 1][r] != INF)
                    ans = min(ans, d);
            }
            else
            {
                for (int d = 0; d < 10; ++d)
                {
                    if (i == 0 and d == 0)
                        continue;
                    auto &ans = dp[i][(r + pten[i] * d) % n];
                    if (dp[i + 1][r] != INF)
                        ans = min(ans, d);
                }
            }
        }
    }
    string ans(m, '?');
    ll     acc = 0;
    if (dp[0][0] == INF)
        return "*";

    ans[0] = '0' + dp[0][0];
    for (int i = 1; i < m; ++i)
    {
        int best = INF;
        acc      = (acc + (ans[i - 1] - '0') * pten[i - 1]) % n;
        for (int r = 0; r < n; ++r)
            if (((r + acc) % n) == 0)
                best = min(best, dp[i][r]);
        ans[i] = '0' + best;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> s >> n;
    cout << solve(s, n) << endl;
    return 0;
}
