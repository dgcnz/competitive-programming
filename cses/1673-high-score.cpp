#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/graph/spfa>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

long long solve(Graph<long long> g)
{
    int                 n  = g.size();
    Graph<long long>    gt = g.transpose();
    vector<bool>        vis(n, false), can_reach_src(n, false);
    function<void(int)> dfs = [&](int u)
    {
        vis[u] = true;
        for (auto [v, w] : gt[u])
        {
            if (!vis[v])
                dfs(v);
            can_reach_src[u] = can_reach_src[u] or can_reach_src[v];
        }
    };

    can_reach_src[0] = true;
    dfs(n - 1);
    if (not can_reach_src[n - 1])
        return -1;

    auto [g_i, id] = g.subgraph(can_reach_src);
    SPFA<long long> spfa(g_i);

    return spfa(id[0]) ? -spfa.dist[id[n - 1]] : -1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    Graph<long long> g(n), gr(n);
    for (int i = 0; i < m; ++i)
    {
        int       u, v;
        long long c;
        cin >> u >> v >> c, u--, v--;
        g.add_edge(u, v, -c);
    }
    cout << solve(g) << endl;

    return 0;
}
