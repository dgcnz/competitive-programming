#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <atcoder/string>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

ll solve(string a, string l, string r)
{
    int          n = a.size(), nl = l.size(), nr = r.size();
    string       sl = l + "#" + a + "@", sr = r + "#" + a + "!";
    auto         zl = z_algorithm(sl), zr = z_algorithm(sr);
    vector<mint> dp(n + 1, 0), pdp(n + 1, 0);

    auto cmpL = [&](int i) {
        return zl[i] == nl ? 0 : sl[i + zl[i]] - sl[zl[i]];
    };
    auto cmpR = [&](int i) {
        return zr[i] == nr ? 0 : sr[i + zr[i]] - sr[zr[i]];
    };
    auto sum = [&](int i, int j) { return pdp[i] - (j >= n ? 0 : pdp[j + 1]); };

    dp[n] = pdp[n] = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == '0')
        {
            if (l == "0")
                dp[i] = dp[i + 1];
        }
        else
        {
            int L = i + nl, R = i + nr;
            if (cmpL(nl + 1 + i) < 0)
                L++;
            if (cmpR(nr + 1 + i) > 0)
                R--;
            if (L <= R and L <= n)
                dp[i] = sum(L, R);
        }
        pdp[i] = dp[i] + pdp[i + 1];
    }
    return dp[0].val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string a, l, r;
    cin >> a >> l >> r;
    cout << solve(a, l, r) << endl;
    return 0;
}
