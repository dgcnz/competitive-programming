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
using ll  = long long;
using ii  = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll x, y, ax, ay, bx, by;
    cin >> x >> y >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;

    ll          INF = 1e16;
    vector<pll> p   = {{x, y}};
    while (x < INF and y < INF)
    {
        x = ax * x + bx;
        y = ay * y + by;
        p.emplace_back(x, y);
    }
    int  n    = p.size();
    auto dist = [](pll p1, pll p2) -> ll {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    };

    int ans = 0;
    for (int l = 0; l < n; ++l)
    {
        for (int r = l; r < n; ++r)
        {
            ll total = dist(p[l], p[r]) +
                       min(dist({xs, ys}, p[l]), dist({xs, ys}, p[r]));
            if (total <= t)
                ans = max(ans, r - l + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
