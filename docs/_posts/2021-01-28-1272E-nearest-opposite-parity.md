---
layout: post
mathjax: true
title: 1272E - Nearest Opposite Parity
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
vi g[NMAX], gi[NMAX], odds, evens;
int n, a[NMAX], visited[NMAX], dp[NMAX];
vi msbfs(vi srcs)
{
    vector<int> visited(n + 1, false);
    queue<int> frontier;
    vector<int> dist(n + 1, -1);
    for (auto x : srcs)
    {
        dist[x] = 0;
        frontier.push(x);
        visited[x] = true;
    }
    while (not frontier.empty())
    {
        auto u = frontier.front();
        frontier.pop();
        for (auto v : gi[u])
        {
            if (not visited[v])
            {
                frontier.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist;
}
int main(void)
{
    cin >> n;
    for (int u = 1; u <= n; ++u)
        cin >> a[u];
    for (int u = 1; u <= n; ++u)
    {
        int l = u - a[u], r = u + a[u];
        if (l >= 1)
            g[u].push_back(l), gi[l].push_back(u);
        if (r <= n)
            g[u].push_back(r), gi[r].push_back(u);
        a[u] &= 1LL;
        if (a[u])
            odds.push_back(u);
        else
            evens.push_back(u);
    }
    vi ans(n + 1);
    auto d1 = msbfs(odds);
    for (int u = 1; u <= n; ++u)
        if (d1[u] != 0)
            ans[u] = d1[u];
    auto d2 = msbfs(evens);
    for (int u = 1; u <= n; ++u)
        if (d2[u] != 0)
            ans[u] = d2[u];
    for (int u = 1; u <= n; ++u)
        cout << ans[u] << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

