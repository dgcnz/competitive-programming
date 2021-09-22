#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint1000000007;

int const                NMAX = 5e6 + 10;
SmallestPrimeSieve<NMAX> sieve;

inline ll sq(ll n) { return (n * (n - 1)) / 2; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t, l, r;
    cin >> t >> l >> r;
    vector<ll> dp(r + 1);

    for (int i = 2; i <= r; ++i)
    {
        int x = sieve.sp[i];
        if (x == i)
            dp[i] = sq(i);
        else
            dp[i] = (i / x) * sq(x) + dp[i / x];
    }

    mint tp = 1, ans = 0;
    for (int i = l; i <= r; ++i)
    {
        ans += tp * dp[i];
        tp *= t;
    }

    cout << ans.val() << endl;
    return 0;
}
