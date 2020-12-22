---
layout: post
mathjax: true
title: 1085D - Minimum Diameter Tree
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
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 1e5 + 11;
int n, s, deg[NMAX];
vi g[NMAX];
void dfs(int u, int p)
{
    deg[u] = 0;
    for (auto v : g[u])
    {
        deg[u]++;
        if (v != p)
            dfs(v, u);
    }
}
int main(void)
{
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int l = count_if(deg + 1, deg + n + 1, [](int d) { return d == 1; });
    cout << fixed << setprecision(12) << (2.0 * s) / (1.0 * l) << endl;
    return 0;
}

{% endraw %}
```
</details>
