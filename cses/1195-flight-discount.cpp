#include <bits/stdc++.h>
#include <cplib/graph/dijkstra>
#include <cplib/graph/graph>

using namespace std;
using namespace cplib;

long long solve(int n, vector<tuple<int, int, int>> edges)
{
    Graph<long long> g(n), gr(n);
    for (auto [u, v, c] : edges)
    {
        g.add_edge(u, v, c);
        gr.add_edge(v, u, c);
    }

    Dijkstra<long long> from_src(g);
    Dijkstra<long long> from_dst(gr);

    from_src(0);     // running dijkstra on G, from 0
    from_dst(n - 1); // running dijkstra on Gr, from n - 1

    long long const INF = 1e18;
    long long       ans = INF;
    for (auto [u, v, c] : edges)
        if (from_src.is_reachable(u) and from_dst.is_reachable(v))
            ans = min(ans, from_src.distance(u) + c / 2 + from_dst.distance(v));
    return ans;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (auto &[u, v, c] : edges)
        cin >> u >> v >> c, u--, v--;

    cout << solve(n, edges) << endl;
    return 0;
}
