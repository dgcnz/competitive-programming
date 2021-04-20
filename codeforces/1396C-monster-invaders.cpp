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

ll solve(vector<ll> a, vector<ll> r, ll d)
{
    int                n   = a.size();
    ll const           INF = 1e16;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));

    dp[0][0] = r[0] * a[0] + r[2];
    dp[0][1] = min(r[1], r[0] * a[0] + r[0]);
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] =
            min({dp[i - 1][0] + d + r[0] * a[i] + r[2],
                 dp[i - 1][1] + d + r[0] * a[i] + r[2] + d + r[0] + d,
                 dp[i - 1][1] + d + r[0] * a[i] + r[0] + d + r[0] + d + r[0],
                 dp[i - 1][1] + d + r[1] + d + r[0] + d + r[0],
                 (i == n - 1 ? dp[i - 1][1] + d + r[0] * a[i] + r[2] + d + r[0]
                             : INF)});

        dp[i][1] = min({dp[i - 1][0] + d + r[0] * a[i] + r[0],
                        dp[i - 1][0] + d + r[1],
                        dp[i - 1][1] + d + r[0] * a[i] + r[0] + d + r[0] + d,
                        dp[i - 1][1] + d + r[1] + d + r[0] + d});
    }
    return dp[n - 1][0];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  d;
    cin >> n;
    vector<ll> r(3);
    read(all(r));
    cin >> d;
    vector<ll> a(n);
    read(all(a));
    cout << solve(a, r, d) << endl;
    return 0;
}
