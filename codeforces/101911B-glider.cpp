#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, h;
    cin >> n >> h;

    vector<ii> x(n + 1, {0, 0});
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i].first >> x[i].second;
        p[i] = p[i - 1] + x[i].first - x[i - 1].second;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        auto non_flyable = lower_bound(all(p), p[i] + h);
        auto flyable     = prev(non_flyable);
        int  ix          = flyable - p.begin();
        ll   rem         = h - (p[ix] - p[i]);
        ll   cur         = x[ix].second - x[i].first + rem;
        ans              = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
