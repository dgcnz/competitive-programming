#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using mint = modint998244353;

int solve(vi x, vi y, vi s)
{
    int n = x.size();

    vector<mint> dp(n), pdp(n);

    pdp[0] = dp[0] = x[0] - y[0];

    auto sum = [&](int l, int r)
    {
        if (l > r)
            return mint(0);
        return pdp[r] - (l > 0 ? pdp[l - 1] : mint(0));
    };

    for (int i = 1; i < n; ++i)
    {
        int j  = upper_bound(all(x), y[i]) - x.begin();
        dp[i]  = x[i] - y[i] + sum(j, i - 1);
        pdp[i] = pdp[i - 1] + dp[i];
    }

    mint ans = 1 + x[0] + dp[0] * s[0];
    for (int i = 1; i < n; ++i)
        ans += x[i] - x[i - 1] + dp[i] * s[i];
    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi x(n), y(n), s(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> s[i];

    cout << solve(x, y, s) << endl;

    return 0;
}
