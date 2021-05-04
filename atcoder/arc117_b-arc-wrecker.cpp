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

ll solve(vector<ll> a)
{
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int          n = a.size();
    vector<mint> dp(n, 0);
    dp[0] = a[0] + 1;
    for (int i = 1; i < n; ++i)
        dp[i] = dp[i - 1] * (a[i] - a[i - 1] + 1);
    return dp[n - 1].val();
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
