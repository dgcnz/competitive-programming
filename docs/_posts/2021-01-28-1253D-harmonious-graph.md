---
layout: post
mathjax: true
title: 1253D - Harmonious Graph
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
using vi = vector<int>;
int const NMAX = 2e5 + 11;
int n, m;
vi g[NMAX];
set<int> edges;
int dfs(int u, vector<bool> &visited)
{
    int maxv = u;
    visited[u] = true;
    for (auto v : g[u])
        if (not visited[v])
            maxv = max(maxv, dfs(v, visited));
    return maxv;
}
int solve(void)
{
    int ans = 0;
    vector<bool> visited(n + 1, false);
    while (not edges.empty())
    {
        int u = *edges.begin(), v = dfs(u, visited);
        for (int i = u; i <= v; ++i)
        {
            if (not visited[i])
            {
                g[u].push_back(i);
                g[i].push_back(u);
                v = max(v, dfs(i, visited));
                ++ans;
            }
            edges.erase(i);
        }
    }
    return ans;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.insert(u), edges.insert(v);
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

