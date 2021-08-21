#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll dist(ll xi, ll xj, ll yi, ll yj) { return abs(xi - xj) + abs(yi - yj); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n), y(n), c(n), k(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> k[i];

    long long              ans = 0;
    vector<int>            power_plants;
    vector<pair<int, int>> connections;

    vector<bool> done(n);
    vector<int>  parent(n, -1);
    for (int _n = n; _n--;)
    {
        int mi = 2000000000;
        int u  = -1;
        for (int i = 0; i != n; ++i)
        {
            if (done[i])
                continue;

            if (c[i] < mi)
            {
                mi = c[i];
                u  = i;
            }
        }

        ans += mi;
        done[u] = 1;
        if (parent[u] == -1)
            power_plants.push_back(u);
        else
            connections.push_back(
                make_pair(min(parent[u], u), max(parent[u], u)));

        for (int i = 0; i != n; ++i)
        {
            ll cost = dist(x[u], x[i], y[u], y[i]);
            if (ll(k[u] + k[i]) * cost < c[i])
            {
                c[i]      = (k[u] + k[i]) * cost;
                parent[i] = u;
            }
        }
    }

    cout << ans << '\n';
    cout << power_plants.size() << '\n';
    sort(all(power_plants));
    for (auto x : power_plants)
        cout << x + 1 << ' ';
    cout << '\n';
    cout << connections.size() << '\n';
    for (auto [i, j] : connections)
        cout << i + 1 << ' ' << j + 1 << '\n';

    return 0;
}
