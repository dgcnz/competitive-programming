/** @file
 * @date                2020-12-17
 * @url                 https://codeforces.com/contest/1463/problem/C
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        2
 * @thinking_time       20
 * @coding_time         30
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Compute the position $y_i$ of the robot at time $t_i$. Then, check if for
 * each $i$, $x_i$ lies in the range $y_i, y_{i + 1}$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

int solve(vector<pll> tx)
{
    tx.emplace_back(1e13, 0);

    int ans = 0, n = isz(tx);
    ll  ts, xs, xe, te;
    ts = xs = xe = te = 0;

    vector<ll> y(n);

    for (int i = 0; i < n; ++i)
    {
        auto [ti, xi] = tx[i];

        y[i] = xs + (xe == xs ? 0 : (xe > xs ? 1 : -1)) * (min(ti, te) - ts);

        if (te <= ti)
        {
            ts = ti;
            xs = xe;

            te = ts + abs(xi - xs);
            xe = xi;
        }
    }

    auto inside = [](ll x, ll l, ll r) -> bool {
        if (l > r)
            swap(l, r);
        return l <= x and x <= r;
    };

    for (int i = 0; i < n - 1; ++i)
        ans += inside(tx[i].second, y[i], y[i + 1]);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<pll> tx(n);
        for (auto &[t, x] : tx)
            cin >> t >> x;

        cout << solve(tx) << endl;
    }
    return 0;
}
