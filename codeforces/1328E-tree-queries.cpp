/** @file
 * @date                2021-02-03
 * @url                 https://codeforces.com/problemset/problem/1328/E
 * @tags                dfs, trees, graphs
 * @status              AC
 * @score               2
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         30
 * @time_complexity     O(n + m + k \log{k})
 * @memory_complexity   O(n)
 * @idea
 * To ease our computations, let's replace all vertices in a query for their
 * parents (in the case of the root, leave it like that). The problem now
 * simplifies into finding if the set of verticies lie on a single path to the
 * root.

 * 1. Sort the vertices non-increasingly in order of depth.
 * 2. For each vertex, if the current vertex is an ancestor of the last vertex
 considered, then you're good.
 *
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
using Graph = vector<vi>;

array<vi, 4> solve(int n, vector<ii> edges)
{
    Graph g(n);
    for (auto [u, v] : edges)
        g[u].push_back(v), g[v].push_back(u);

    vi                  depth(n, 0), parent(n, -1), tin(n, 0), tout(n, 0);
    int                 timer = 0;
    function<void(int)> dfs   = [&](int u) {
        tin[u] = ++timer;
        for (auto v : g[u])
        {
            if (v == parent[u])
                continue;
            depth[v]  = depth[u] + 1;
            parent[v] = u;
            dfs(v);
        }
        tout[u] = ++timer;
    };

    dfs(0);
    return {parent, depth, tin, tout};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ii> edges(n - 1);
    for (auto &[u, v] : edges)
        cin >> u >> v, u--, v--;

    auto [parent, depth, tin, tout] = solve(n, edges);

    auto is_ancestor = [&](int u, int v) {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    };

    while (m--)
    {
        int k;
        cin >> k;
        set<ii, greater<ii>> sorted;
        for (int i = 0; i < k; ++i)
        {
            int u;
            cin >> u, u--;
            u = u == 0 ? u : parent[u];
            sorted.emplace(depth[u], u);
        }

        bool flag = true;
        int  cur  = sorted.begin()->second;
        for (auto [d, u] : sorted)
        {
            if (not is_ancestor(u, cur) and u != cur)
            {
                flag = false;
                break;
            }
            cur = u;
        }

        cout << (flag ? "YES" : "NO") << endl;
    };
    return 0;
}
