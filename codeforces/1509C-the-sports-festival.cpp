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

ll solve(vector<ll> s)
{
    int                n   = s.size();
    ll const           INF = 1e17; // check
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    sort(all(s));

    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;
    for (int r = 1; r < n; ++r)
        for (int l = r - 1; l >= 0; --l)
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + s[r] - s[l];
    return dp[0][n - 1];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> s(n);
    read(all(s));
    cout << solve(s) << endl;
    return 0;
}
