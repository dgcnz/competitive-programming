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
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;
template <class T>
T count(T n, T div, T rem)
{
    return (n + div - rem - 1) / div;
}
template <class T>
T count(T min, T max, T div, T rem)
{
    return count(max + 1, div, rem) - count(min, div, rem);
}

int solve(int n, ll l, ll r)
{
    vector<vector<mint>> dp(n + 1, vector<mint>(3, 0));
    dp[0][0] = 1;

    vector<ll> rem(3, 0);
    for (int rr = 0; rr < 3; ++rr)
        rem[rr] = count(l, r, 3LL, (ll)rr);

    for (int i = 1; i <= n; ++i)
        for (int r1 = 0; r1 < 3; ++r1)
            for (int r2 = 0; r2 < 3; ++r2)
                dp[i][(r1 + r2) % 3] += rem[r1] * dp[i - 1][r2];
    return dp[n][0].val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l, r) << endl;
    return 0;
}
