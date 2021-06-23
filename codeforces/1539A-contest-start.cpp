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

ll solve(ll n, ll x, ll t)
{
    ll k   = min(n, t / x);
    ll ans = (n - k) * k + ((k - 1) * k) / 2;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        ll n, x, t;
        cin >> n >> x >> t;
        cout << solve(n, x, t) << endl;
    }
    return 0;
}
