---
layout: post
mathjax: true
title: 741B Arpa Weak Amphitheater Valuable Hoses
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

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
int const NMAX = 1e3 + 11;
int n, m, c, w[NMAX], b[NMAX], rep[NMAX], cur_rep;
bool visited[NMAX];
vi g[NMAX], component;
inline pair<int, int> add_pair(pair<int, int> a, pair<int, int> b)
{
    return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> dfs(int u, int p = -1)
{
    pair<int, int> tbw = {b[u], w[u]};
    rep[u] = cur_rep;
    visited[u] = true;
    for (auto v : g[u])
    {
        if (v == p or visited[v])
            continue;
        tbw = add_pair(dfs(v, u), tbw);
    }
    component.push_back(u);
    return tbw;
}
int solve(void)
{
    vector<vi> dp(n + 1, vi(c + 1, 0));
    for (int u = 1; u <= n; ++u)
    {
        if (visited[u])
            continue;
        ++cur_rep;
        auto [tb, tw] = dfs(u);
        for (int cap = 0; cap <= c; ++cap)
        {
            auto &ans = dp[cur_rep][cap];
            ans = max(ans, dp[cur_rep - 1][cap]);
            if (cap - tw >= 0)
                ans = max(ans, dp[cur_rep - 1][cap - tw] + tb);
            for (auto v : component)
                if (cap - w[v] >= 0)
                    ans = max(ans, dp[cur_rep - 1][cap - w[v]] + b[v]);
        }
        component.clear();
    }
    return dp[cur_rep][c];
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int u, v;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```