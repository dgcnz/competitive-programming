---
layout: post
mathjax: true
title: 61D Eternal Victory
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
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
const int NMAX = 1e5 + 11;
vii g[NMAX];
int cost[NMAX];
ll dp[NMAX], dp2[NMAX];
void compdp(int u, int p)
{
    dp[u] = 0;
    dp2[u] = 0;
    ll vmin = LLONG_MAX;
    for (auto [v, c] : g[u])
    {
        if (v == p)
            continue;
        cost[v] = c;
        compdp(v, u);
        dp[u] += dp[v] + 2 * c;
        vmin = min(vmin, dp2[v] - dp[v] - c);
    }
    dp2[u] = dp[u];
    if (vmin != LLONG_MAX)
        dp2[u] += vmin;
}
int main(void)
{
    int n, x, y, w;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    compdp(1, 0);
    cout << dp2[1] << endl;
    return 0;
}

{% endraw %}
```