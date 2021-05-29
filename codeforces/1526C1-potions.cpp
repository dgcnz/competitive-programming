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

int solve(vector<ll> a)
{
    int                n = a.size();
    vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));

    for (int i = 0; i < n; ++i)
        dp[i][0] = 0;

    if (a[0] >= 0)
        dp[0][1] = a[0];

    for (int i = 1; i < n; ++i)
    {
        for (int k = 1; k <= n; ++k)
        {
            auto &ans = dp[i][k] = dp[i - 1][k];
            if (dp[i - 1][k - 1] >= 0)
                ans = max(ans, dp[i - 1][k - 1] + a[i]);
        }
    }
    for (int k = n; k >= 0; --k)
        if (dp[n - 1][k] >= 0)
            return k;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    cout << solve(a) << endl;
    return 0;
}
