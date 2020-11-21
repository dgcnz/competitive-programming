---
layout: post
mathjax: true
title: 1132 Tree Distances I
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
using vi = vector<int>;
int const NMAX = 2e5 + 11;
int n, ddown[NMAX], ans[NMAX];
vi g[NMAX];
void dp(int u, int p = -1)
{
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dp(v, u);
        ddown[u] = max(ddown[u], ddown[v] + 1);
    }
}
void reroot(int u, int p = -1, int dup = 0)
{
    ans[u] = max(ddown[u], dup);
    vector<ii> dists = {{dup, -1}, {0, -1}};
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dists.emplace_back(ddown[v] + 1, v);
    }
    sort(dists.begin(), dists.end(), greater<ii>());
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        reroot(v,
               u,
               dists[0].second == v ? dists[1].first + 1 : dists[0].first + 1);
    }
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp(1);
    reroot(1);
    for (int u = 1; u <= n; ++u)
        cout << ans[u] << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
