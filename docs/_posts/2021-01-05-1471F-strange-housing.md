---
layout: post
mathjax: true
title: 1471F - Strange Housing
problem_url: https://codeforces.com/contest/1471/problem/F
tags: dfs, graphs, greedy
memory_complexity: O(n + m)
time_complexity: O(n + m)
---

Essentially, 2-coloring the graph with a dfs does the job.
[Editorial](https://codeforces.com/blog/entry/86464).


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
using Graph = vector<vector<int>>;
struct DFS
{
    Graph & g;
    vector<bool> vis;
    vector<int> &color, &ans;
    DFS(Graph &g, vector<int> &color, vector<int> &ans)
        : g(g), vis((int)(g).size(), 0), color(color), ans(ans)
    {
    }
    void traverse(int u)
    {
        vis[u] = true;
        if (none_of(begin(g[u]), end(g[u]), [this](int v) { return vis[v] and color[v]; }))
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
    int n = (int)(g).size();
    vector<int> color(n, 0), ans;
    color[0] = 1;
    DFS dfs(g, color, ans);
    dfs(0);
    if (any_of(begin(dfs.vis), end(dfs.vis), [](bool vis) { return !vis; }))
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

{% endraw %}
```
</details>

