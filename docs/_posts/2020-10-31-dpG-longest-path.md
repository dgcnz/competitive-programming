---
layout: post
mathjax: true
title: Dpg Longest Path
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
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m, mem[NMAX];
bool vis[NMAX];
vi g[NMAX];
int dp(int u)
{
    int ans = 0;
    if (vis[u])
        return mem[u];
    vis[u] = true;
    for (auto v : g[u])
        ans = max(dp(v) + 1, ans);
    return (mem[u] = ans);
}
int main(void)
{
    int u, v, ans;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, dp(i));
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
