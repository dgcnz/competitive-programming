---
layout: post
mathjax: true
title: 574B - Bear And Three Musketeers
problem_url: https://codeforces.com/problemset/problem/574/B
tags: graphs, brute_force
memory_complexity: O(n^2)
time_complexity: O(n^2 + mn)
---

The [Editorial](https://codeforces.com/blog/entry/20040) mentions an
interesting trick to reduce complexity from $O(n^3)$ to $O(n^2 + mn)$.

Iterate pairs, $(u, v)$, and only check for a third vertex, $c$ ,if there
already exists an edge between $(u, v)$. edge between the pair. In this way
we are checking for each edge, $O(m)$, a third vertex $c$.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> g(n, vi(n, 0));
    vector<int> d(n, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        d[u]++, d[v]++;
        g[u][v]++, g[v][u]++;
    }
    int const INF = 1e9;
    int ans = INF;
    for (int u = 0; u < n; ++u)
    {
        for (int v = u + 1; v < n; ++v)
        {
            if (g[u][v])
            {
                for (int c = v + 1; c < n; ++c)
                {
                    if (g[u][c] and g[v][c])
                        ans = min(ans, d[u] + d[v] + d[c]);
                }
            }
        }
    }
    cout << (ans == INF ? -1 : ans - 6) << endl;
    return 0;
}

{% endraw %}
```
</details>

