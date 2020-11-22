---
layout: post
mathjax: true
title: 1195 Flight Discount
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;
using viii = vector<array<int, 3>>;
const ll INF = 1e16;
vll dijkstra(vii g[], int n, int src)
{
    vector<long long> distance(n + 1, INF);
    vector<bool> processed(n + 1, false);
    priority_queue<pair<ll, int>> q;
    distance[src] = 0;
    q.push({0, src});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (processed[u])
            continue;
        processed[u] = true;
        for (auto [v, c] : g[u])
        {
            if (distance[u] + c < distance[v])
            {
                distance[v] = distance[u] + c;
                q.push({-distance[v], v});
            }
        }
    }
    return distance;
}
int main(void)
{
    int n, m, u, v, c;
    cin >> n >> m;
    vii g[n + 1], gi[n + 1];
    viii edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        gi[v].emplace_back(u, c);
        edges[i] = {u, v, c};
    }
    auto from_src = dijkstra(g, n, 1);
    auto to_dst = dijkstra(gi, n, n);
    ll ans = INF;
    for (auto [u, v, c] : edges)
        ans = min(ans, from_src[u] + c / 2 + to_dst[v]);
    cout << ans << endl;
    return 0;
}

{% endraw %}
```