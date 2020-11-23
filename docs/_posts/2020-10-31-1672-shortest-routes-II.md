---
layout: post
mathjax: true
title: 1672 Shortest Routes Ii
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
template <typename T>
using vx = vector<T>;
template <typename T>
using vvx = vector<vx<T>>;
const ll INF = 1e16;
const vvx<ll> floyd_warshall(int n, const vvx<int> &g)
{
    vvx<ll> dist(n + 1, vx<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (g[i][j])
                dist[i][j] = g[i][j];
            else
                dist[i][j] = INF;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}
int main(void)
{
    int n, m, q, u, v, w;
    cin >> n >> m >> q;
    vvx<int> g(n + 1, vx<int>(n + 1, 0));
    while (m--)
    {
        cin >> u >> v >> w;
        if (g[u][v])
            w = min(w, g[u][v]);
        g[u][v] = w;
        g[v][u] = w;
    }
    auto ans = floyd_warshall(n, g);
    while (q--)
    {
        cin >> u >> v;
        cout << (ans[u][v] == INF ? -1 : ans[u][v]) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

