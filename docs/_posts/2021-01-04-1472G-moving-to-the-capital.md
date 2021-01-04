---
layout: post
mathjax: true
title: 1472G - Moving To The Capital
problem_url: https://codeforces.com/contest/1472/problem/G
tags: dp, graphs, dfs
memory_complexity: O(n + m)
time_complexity: O(n + m)
---

Let's call "back-edges" to those edges $(u, v)$ such that $d(v) \leq d(u)$.
Such edges would require move $2$ to be used. We can easily find the
distances, $d$, and the back edges with a bfs.

Having done that, we can define the following dp:

$$
dp(u) = min
\begin{cases}
d(u), \\
d(v), \text{ if } (u, v) \text{ is a back edge} \\
dp(v) \text{ otherwise} \\
\end{cases}
$$



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using Graph = vector<vector<ii>>;
struct BFS
{
    Graph & g;
    vector<bool> vis;
    vector<int> d;
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
                    d[v] = d[u] + 1;
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
    vi & dp, d;
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
    vi dp(bfs.d);
    DFS dfs(g, dp, bfs.d);
    for (int u = 1, n = (int)(g).size(); u < n; ++u)
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

{% endraw %}
```
</details>

