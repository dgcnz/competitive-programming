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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int const    NMAX = 2e6 + 11;
    vector<mint> dp(NMAX, 0);
    dp[2] = 4;
    for (int i = 3; i < NMAX; ++i)
        dp[i] = dp[i - 1] + 2 * dp[i - 2] + 4 * (i % 3 == 2);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n - 1].val() << endl;
    }
    return 0;
}
