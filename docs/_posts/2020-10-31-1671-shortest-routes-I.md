---
layout: post
mathjax: true
title: 1671 Shortest Routes I
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
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using lli = pair<ll, int>;
template <typename T>
using pqueue = priority_queue<T>;
const int NMAX = 1e5 + 11;
const ll INF = 1e16;
int n, m;
vii g[NMAX];
vector<ll> dijkstra(int start)
{
    pqueue<lli> q;
    vector<ll> distance(n + 1, INF);
    vector<bool> processed(n + 1, false);
    distance[start] = 0;
    q.push({0, start});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (processed[u])
            continue;
        processed[u] = true;
        for (auto [v, w] : g[u])
        {
            if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                q.push({-distance[v], v});
            }
        }
    }
    return distance;
}
int main(void)
{
    int u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(v, w);
    }
    auto ans = dijkstra(1);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
