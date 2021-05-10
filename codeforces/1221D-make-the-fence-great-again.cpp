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
using ll  = long long;
using ii  = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;

ll solve(vector<ll> a, vector<ll> b)
{
    int                n    = a.size();
    ll const           INF  = 1e18 + 10;
    int const          MINC = 3;
    vector<vector<ll>> dp(n, vector<ll>(MINC, INF));
    for (int k = 0; k < MINC; ++k)
        dp[0][k] = k * b[0];
    for (int i = 1; i < n; ++i)
    {
        for (int k = 0; k < MINC; ++k)
        {
            auto &ans = dp[i][k];
            for (int x = 0; x < MINC; ++x)
                if (a[i - 1] + x != a[i] + k)
                    ans = min(ans, dp[i - 1][x]);
            ans += k * b[i];
        }
    }
    return *min_element(all(dp[n - 1]));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        cout << solve(a, b) << endl;
    }
    return 0;
}
