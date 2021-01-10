/** @file
 * @date                2021-01-10
 * @url                 https://atcoder.jp/contests/abc188/tasks/abc188_e
 * @tags                graphs, dp, dfs
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * Given the $X_i < Y_i$ constraint, we know this is a DAG.
 *
 * For each node, $u$, with neighbor set $N(u)$, we'll compute the following two
 * values:
 *
 * ```
 * sell[u] = max(a[u], {sell[v] | v <- N(u)})
 * ans[u] = max({-a[u] + sell[v] | v <- N(u)})
 * ```
 *
 * Where `sell[u]` denotes the best price to sell for all nodes reachable by $u$
 * and itself and `ans[u]` is the best return value if we buy at node $u$ and
 * sell at some node reachable by $u$.
 *
 * The final answer is the maximum of $ans$ over all nodes.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using vll   = vector<ll>;
using Graph = vector<vi>;

struct DFS
{
    Graph &g;
    vll &  a, &ans, &sell;

    vector<bool> vis;
    DFS(Graph &g, vll &a, vll &ans, vll &sell)
        : g(g), a(a), ans(ans), sell(sell), vis(isz(g), 0){};

    void traverse(int u)
    {
        vis[u] = true;
        for (auto v : g[u])
        {
            if (!vis[v])
                traverse(v);
            sell[u] = max(sell[u], sell[v]);
            ans[u]  = max(ans[u], -a[u] + sell[v]);
        }
    }
    void operator()(int u) { traverse(u); }
};

ll solve(Graph g, vll a)
{
    const ll INF = 1e17;

    int n = isz(g);
    vll ans(n, -INF), sell(a);

    DFS dfs(g, a, ans, sell);
    for (int u = 0; u < n; ++u)
        if (not dfs.vis[u])
            dfs(u);

    return *max_element(all(ans));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vll a(n);
    for (auto &ai : a)
        cin >> ai;

    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
    }

    cout << solve(g, a) << endl;

    return 0;
}
