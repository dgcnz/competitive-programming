---
layout: post
title: 1187E Tree Painting
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
using ll = long long;
const int NMAX = 2e5 + 11;
vi g[NMAX];
int sz[NMAX];
ll dp[NMAX], ans = 0;
int compsz(int u, int p)
{
    sz[u] = 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        sz[u] += compsz(v, u);
    }
    return sz[u];
}
ll compdp(int u, int p)
{
    dp[u] = sz[u];
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dp[u] += compdp(v, u);
    }
    return dp[u];
}
void dfs(int u, int p)
{
    ans = max(ans, dp[u]);
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dp[u] -= dp[v];
        dp[u] -= sz[v];
        sz[u] -= sz[v];
        dp[v] += dp[u];
        dp[v] += sz[u];
        sz[v] += sz[u];
        dfs(v, u);
        sz[v] -= sz[u];
        dp[v] -= sz[u];
        dp[v] -= dp[u];
        sz[u] += sz[v];
        dp[u] += sz[v];
        dp[u] += dp[v];
    }
}
int main(void)
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    compsz(0, -1);
    compdp(0, -1);
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
