#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/dijkstra>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(int n, vi a, vector<ii> edges)
{
    int          k = a.size();
    Dijkstra<ll> g(n);
    for (auto [u, v] : edges)
        g.add_edge(u, v), g.add_edge(v, u);

    g(0);
    vector<ll> dsrc = g.d;
    g(n - 1);
    vector<ll> dsink = g.d;

    auto cmp = [&](int i, int j) { return dsrc[i] < dsrc[j]; };
    sort(all(a), cmp);

    vector<ll> furthest(k, 0);
    furthest[k - 1] = dsink[a[k - 1]];
    for (int i = k - 2; i >= 0; --i)
        furthest[i] = max(furthest[i + 1], dsink[a[i]]);
    ll ans = 0;
    for (int i = 0; i < k - 1; ++i)
    {
        int j   = a[i];
        ll  cur = min(
            {dsrc[n - 1], dsrc[j] + dsink[j], dsrc[j] + 1 + furthest[i + 1]});
        ans = max(ans, cur);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    vi a(k);
    read(all(a));
    transform(all(a), begin(a), [](int ai) { return ai - 1; });
    vector<ii> edges(m);
    for (auto &[u, v] : edges)
        cin >> u >> v, u--, v--;

    cout << solve(n, a, edges) << endl;

    return 0;
}
