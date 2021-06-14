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
    int n, m;
    cin >> n >> m;
    Graph<int> g(51 * n);
    auto       add_edge = [&](int u, int v, int w) {
        g.add_edge(u * 51, 51 * v + w, 0);
        for (int c = 1; c <= 50; ++c)
            g.add_edge(51 * u + c, 51 * v, (c + w) * (c + w));
    };
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    Dijkstra<int> dijkstra(g);
    dijkstra(0);

    for (int u = 0; u < n; ++u)
        cout << (dijkstra.is_reachable(51 * u) ? dijkstra.distance(51 * u) : -1)
             << ' ';
    cout << endl;

    return 0;
}
