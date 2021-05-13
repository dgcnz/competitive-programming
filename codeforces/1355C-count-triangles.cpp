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

ll solve(int a, int b, int c, int d)
{
    int const  NMAX = 1e6 + 100;
    vector<ll> dp(NMAX, 0);
    for (int x = a; x <= b; ++x)
        dp[x + b]++, dp[x + c + 1]--;
    partial_sum(all(dp), begin(dp));
    partial_sum(all(dp), begin(dp));

    ll ans = 0;
    for (int z = c; z <= d; ++z)
        ans += dp.back() - dp[z];
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
    return 0;
}
