---
layout: post
title: 102433C Coloring Contention
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 1e5 + 100;
int n, m, dist[NMAX];
bool vis[NMAX];
vi g[NMAX];
void bfs(int u)
{
    queue<int> q;
    vis[u] = true;
    q.push(u);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (not vis[v])
            {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(void)
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    cout << dist[n] - 1 << endl;
    return 0;
}

{% endraw %}
```
