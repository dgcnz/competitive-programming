#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/dijkstra>
#include <cplib/graph/graph>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t, s--, t--;

    Graph<ll> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d, u--, v--;
        g.add_undirected_edge(u, v, ll(d));
    }

    pair<ll, int> ans = {-1, -1};
    for (int i = 0; i < n; ++i)
    {
        Dijkstra dijkstra(g);
        if (i != s and i != t)
        {
            dijkstra.run_avoid(s, i);
            auto d = dijkstra.distance(t);
            if (dijkstra.is_reachable(t))
                ans = max(ans, {d, i});
        }
    }
    cout << ans.second + 1 << endl;
    return 0;
}
