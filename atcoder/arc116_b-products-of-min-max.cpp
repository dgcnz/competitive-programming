#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

ll solve(vector<ll> a)
{
    sort(all(a));
    a.erase(remove(all(a), 0LL), a.end());
    int n = a.size();

    if (n == 0)
        return 0;

    vector<mint> dp(n);

    mint ans = mint(a[0]) * a[0];
    dp[0]    = 0;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = (2 * a[i] * dp[i - 1]) / a[i - 1] + mint(a[i - 1]) * a[i];
        ans += dp[i] + mint(a[i]) * a[i];
    }
    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a) << endl;

    return 0;
}
