---
layout: post
title: Abc070_D Transit Tree Path
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

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
