---
layout: post
mathjax: true
title: abc070_d - Transit Tree Path
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
using ii = pair<int, int>;
using ll = long long;
int const NMAX = 1e5 + 11;
int n;
ll dist[NMAX];
vector<ii> g[NMAX];
void dfs(int u, int p = -1, ll d = 0)
{
    dist[u] = d;
    for (auto [v, c] : g[u])
        if (v != p)
            dfs(v, u, d + c);
}
int main(void)
{
    int q, k, u, v, c;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> c, u--, v--;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    cin >> q >> k, k--;
    dfs(k);
    while (q--)
    {
        cin >> u >> v, u--, v--;
        cout << dist[u] + dist[v] << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

