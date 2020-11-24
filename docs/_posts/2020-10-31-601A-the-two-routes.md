---
layout: post
mathjax: true
title: 601A - The Two Routes
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
int const NMAX = 4e2 + 11;
int const INF = 1e9;
int n, gb[NMAX][NMAX], gt[NMAX][NMAX];
int bfs(int g[NMAX][NMAX], int s, int t)
{
    vector<bool> visited(n, false);
    vector<int> d(n);
    queue<int> frontier;
    visited[s] = true;
    frontier.push(s);
    while (not frontier.empty())
    {
        int u = frontier.front();
        frontier.pop();
        if (u == t)
            return d[t];
        for (int v = 0; v < n; ++v)
        {
            if (g[u][v] and not visited[v])
            {
                d[v] = d[u] + 1;
                visited[v] = true;
                frontier.push(v);
            }
        }
    }
    return INF;
}
int main(void)
{
    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            gb[i][j] = gb[j][i] = true;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        gt[u][v] = gt[v][u] = true;
        gb[u][v] = gb[v][u] = false;
    }
    auto anst = bfs(gt, 0, n - 1);
    auto ansb = bfs(gb, 0, n - 1);
    if (anst == INF or ansb == INF)
        cout << -1 << endl;
    else
        cout << max(anst, ansb) << endl;
    return 0;
}

{% endraw %}
```
</details>

