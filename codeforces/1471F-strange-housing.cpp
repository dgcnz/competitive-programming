/** @file
 * @date                2021-01-05
 * @url                 https://codeforces.com/contest/1471/problem/F
 * @tags                dfs, graphs, greedy
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       50
 * @coding_time         30
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * Essentially, 2-coloring the graph with a dfs does the job.
 * [Editorial](https://codeforces.com/blog/entry/86464).
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using Graph = vector<vector<int>>;

struct DFS
{
    Graph &      g;
    vector<bool> vis;
    vector<int> &color, &ans;

    DFS(Graph &g, vector<int> &color, vector<int> &ans)
        : g(g), vis(isz(g), 0), color(color), ans(ans)
    {
    }
    void traverse(int u)
    {
        vis[u] = true;
        if (none_of(all(g[u]), [this](int v) { return vis[v] and color[v]; }))
        {
            color[u] = 1;
            ans.push_back(u);
        }

        for (auto v : g[u])
            if (not vis[v])
                traverse(v);
    }
    void operator()(int u) { traverse(u); }
};

vi solve(Graph g)
{
    int         n = isz(g);
    vector<int> color(n, 0), ans;
    color[0] = 1;

    DFS dfs(g, color, ans);
    dfs(0);

    if (any_of(all(dfs.vis), [](bool vis) { return !vis; }))
        return {};
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Graph g(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (auto ans = solve(g); ans.size() > 0)
        {
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for (auto x : ans)
                cout << x + 1 << " ";
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
