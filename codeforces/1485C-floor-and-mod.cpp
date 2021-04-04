#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(ll x, ll y)
{
    ll ans = 0;
    for (ll r = 1; r < y and r * r < x; ++r)
    {
        ll bmin = r + 1, bmax = y;
        ll amax = min((bmax + 1) * r, x), amin = r * (bmin + 1);
        ans += max(amax / r - ceil(amin, r) + 1, 0LL);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
