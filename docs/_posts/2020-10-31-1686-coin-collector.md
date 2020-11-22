---
layout: post
mathjax: true
title: 1686 Coin Collector
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
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m, n_comp, comp[NMAX];
bool vis[NMAX];
ll ans, coins[NMAX], comp_coins[NMAX], dp[NMAX];
vi g[NMAX], gi[NMAX], gc[NMAX], order;
void toposort(int u)
{
    vis[u] = true;
    for (auto v : g[u])
        if (not vis[v])
            toposort(v);
    order.push_back(u);
}
void build_ssc(int u)
{
    comp[u] = n_comp;
    comp_coins[n_comp] += coins[u];
    for (auto v : gi[u])
        if (comp[v] == -1)
            build_ssc(v);
}
void dfs(int u)
{
    for (auto v : gc[u])
    {
        if (not dp[v])
            dfs(v);
        dp[u] = max(dp[u], dp[v]);
    }
    dp[u] += comp_coins[u];
}
int main(void)
{
    int u, v;
    cin >> n >> m;
    for_each(coins, coins + n, [](ll &c) { cin >> c; });
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }
    for (int u = 0; u < n; ++u)
        if (not vis[u])
            toposort(u);
    memset(comp, -1, sizeof(comp));
    for_each(order.rbegin(), order.rend(), [](int u) {
        if (::comp[u] == -1)
            ::build_ssc(u), ++::n_comp;
    });
    for (int u = 0; u < n; ++u)
        for (auto v : g[u])
            if (comp[u] != comp[v])
                gc[comp[u]].push_back(comp[v]);
    for (int u = 0; u < n_comp; ++u)
        if (not dp[u])
            dfs(u), ans = max(ans, dp[u]);
    cout << ans << endl;
    return 0;
}

{% endraw %}
```