/** @file
 * @date                2021-01-04
 * @url                 https://codeforces.com/contest/1472/problem/G
 * @tags                dp, graphs, dfs
 * @status              AC
 * @score               4
 * @difficulty          4
 * @editorial           no
 * @reading_time        3
 * @thinking_time       60
 * @coding_time         20
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * Let's call "back-edges" to those edges $(u, v)$ such that $d(v) \leq d(u)$.
 * Such edges would require move $2$ to be used. We can easily find the
 * distances, $d$, and the back edges with a bfs.
 *
 * Having done that, we can define the following dp:
 *
 * $$
 * dp(u) = min
 * \begin{cases}
 * d(u), \\
 * d(v), \text{ if } (u, v) \text{ is a back edge} \\
 * dp(v) \text{ otherwise} \\
 * \end{cases}
 * $$
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using Graph = vector<vector<ii>>;

struct BFS
{
    Graph &      g;
    vector<bool> vis;
    vector<int>  d;

    BFS(Graph &g) : g(g), vis(g.size(), 0), d(g.size(), 0) {}
    void traverse(int start)
    {
        queue<int> q;

        q.push(start);
        vis[start] = true;

        while (not q.empty())
        {
            auto u = q.front();
            q.pop();
            for (auto &[v, back] : g[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    d[v]   = d[u] + 1;
                    q.push(v);
                }
                else if (d[v] <= d[u])
                    back = true;
            }
        }
    }
    void operator()(int start) { traverse(start); }
};

struct DFS
{
    Graph &g;
    vi &   dp, d;

    vector<bool> vis;

    DFS(Graph &g, vi &dp, vi d) : g(g), dp(dp), d(d), vis(g.size(), 0) {}
    void traverse(int u)
    {
        vis[u] = true;
        for (auto [v, back] : g[u])
        {
            if (!back and !vis[v])
                traverse(v);
            if (back)
                dp[u] = min(dp[u], d[v]);
            else
                dp[u] = min(dp[u], dp[v]);
        }
    }
    void operator()(int u) { traverse(u); }
};

vi solve(Graph &g)
{
    BFS bfs(g);
    bfs(0);

    vi  dp(bfs.d);
    DFS dfs(g, dp, bfs.d);

    for (int u = 1, n = isz(g); u < n; ++u)
        if (!dfs.vis[u])
            dfs(u);
    return dp;
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
            g[u].emplace_back(v, false);
        }

        auto ans = solve(g);
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
