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
using mint = modint998244353;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<mint> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    mint sum      = 1;

    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            d[j]++;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = sum + d[i];
        sum += dp[i];
    }
    cout << dp[n].val() << endl;
    return 0;
}
