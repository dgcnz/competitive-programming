---
layout: post
mathjax: true
title: 1144F - Graph Without Long Directed Paths
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
int const NMAX = 2e5 + 11;
int n, m;
vi g[NMAX];
ii edges[NMAX];
bool color[NMAX];
bool bfs(int src)
{
    queue<int> frontier;
    vector<bool> visited(n + 1, false);
    frontier.push(src);
    color[src] = 1;
    while (not frontier.empty())
    {
        auto u = frontier.front();
        frontier.pop();
        for (auto v : g[u])
        {
            if (not visited[v])
            {
                frontier.push(v);
                color[v] = !color[u];
                visited[v] = true;
            }
            else if (visited[v] and color[v] == color[u])
                return false;
        }
    }
    return true;
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
        edges[i] = {u, v};
    }
    if (bfs(1))
    {
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i)
        {
            auto [u, v] = edges[i];
            cout << color[u];
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}

{% endraw %}
```
</details>

