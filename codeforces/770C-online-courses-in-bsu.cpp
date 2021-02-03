/** @file
 * @date                2021-02-01
 * @url                 https://codeforces.com/problemset/problem/770/C
 * @tags                dfs, toposort, dag, graphs
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       7
 * @coding_time         15
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * Let's denote $g$, the graph of dependencies and $gr$ the graph of reversed
 * dependencies.
 *
 * Algorithm:
 * 1. Run a dfs from each main course in $gr$ and tag them. This will ensure
 * that we know all our necessary dependencies.
 * 2. Now, remove all edges from $g$ that contain non-tagged vertices.
 * 3. Toposort and remove non-tagged vertices from the order.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/toposort>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Graph = vector<vi>;

vector<int> solve(int n, vector<ii> edges, vi core)
{
    Graph gr(n), g(n);
    for (auto [u, v] : edges)
        gr[v].push_back(u);

    vector<bool>        vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : gr[u])
            if (not vis[v])
                dfs(v);
    };
    for (auto u : core)
        if (not vis[u])
            dfs(u);

    for (auto [u, v] : edges)
        if (vis[u] and vis[v])
            g[u].push_back(v);

    auto ans = toposort(g);
    auto it  = remove_if(all(ans), [&](int u) { return not vis[u]; });
    ans.erase(it, end(ans));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi core(k);

    for (auto &u : core)
        cin >> u, u--;

    vector<ii> edges;
    for (int v = 0; v < n; ++v)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int u;
            cin >> u, u--;
            edges.emplace_back(u, v);
        }
    }

    if (auto ans = solve(n, edges, core); not ans.empty())
    {
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x + 1 << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}
