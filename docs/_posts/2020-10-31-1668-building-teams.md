---
layout: post
mathjax: true
title: 1668 Building Teams
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m, group[NMAX];
vi g[NMAX];
bool dfs(int u, int p, int gr)
{
    group[u] = gr;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        if (group[v] and group[v] == group[u])
            return false;
        if (not group[v] and not dfs(v, u, (gr == 1 ? 2 : 1)))
            return false;
    }
    return true;
}
bool bipartite_check(void)
{
    for (int u = 1; u <= n; ++u)
    {
        if (not group[u])
            if (dfs(u, 0, 1) == false)
                return false;
    }
    return true;
}
int main(void)
{
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (bipartite_check())
    {
        for (int i = 1; i <= n; ++i)
            cout << group[i] << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

{% endraw %}
```
