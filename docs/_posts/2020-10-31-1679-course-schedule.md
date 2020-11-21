---
layout: post
mathjax: true
title: 1679 Course Schedule
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m;
vi g[NMAX], ans, color;
bool dfs(int u)
{
    if (color[u] == 1)
        return false;
    if (color[u] == 2)
        return true;
    color[u] = 1;
    for (int v : g[u])
    {
        if (not dfs(v))
            return false;
    }
    color[u] = 2;
    ans.push_back(u);
    return true;
}
bool toposort(void)
{
    color.assign(n + 1, 0);
    for (int u = 1; u <= n; ++u)
    {
        if (not color[u] and not dfs(u))
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
    }
    if (toposort())
        for_each(ans.rbegin(), ans.rend(), [](int x) { cout << x << " "; }),
            cout << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

{% endraw %}
```
