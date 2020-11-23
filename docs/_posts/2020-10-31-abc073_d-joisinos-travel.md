---
layout: post
mathjax: true
title: Abc073_D Joisinos Travel
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
using vi = vector<int>;
using ll = long long;
int const NMAX = 200 + 11;
ll const INF = 1e15;
int n, m, g[NMAX][NMAX];
ll dist[NMAX][NMAX];
void floyd_warshall(void)
{
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
}
int main(void)
{
    int rn, u, v, c;
    vi r;
    cin >> n >> m >> rn;
    r.resize(rn);
    for (auto &ri : r)
        cin >> ri;
    while (m--)
    {
        cin >> u >> v >> c;
        g[u][v] = g[v][u] = (g[u][v] == 0 ? c : min(g[u][v], c));
    }
    sort(r.begin(), r.end());
    floyd_warshall();
    ll ans = INF, cur;
    do
    {
        cur = 0;
        for (int i = 1; i < rn; ++i)
            cur += dist[r[i - 1]][r[i]];
        ans = min(ans, cur);
    } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

