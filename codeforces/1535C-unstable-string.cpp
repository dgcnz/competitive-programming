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

ll solve(string s)
{
    int                n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    if (s[0] == '?')
        dp[0][0] = dp[0][1] = 1;
    else
        dp[0][s[0] - '0'] = 1;

    ll ans = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == '?')
            for (int b = 0; b < 2; ++b)
                dp[i][b] = dp[i - 1][1 - b] + 1;
        else
        {
            int b    = s[i] - '0';
            dp[i][b] = dp[i - 1][1 - b] + 1;
        }
        ans += max(dp[i][0], dp[i][1]);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
