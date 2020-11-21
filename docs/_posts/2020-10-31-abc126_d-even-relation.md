---
layout: post
title: Abc126_D Even Relation
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
using vii = vector<ii>;
int const NMAX = 1e5 + 11;
int n, color[NMAX];
vii g[NMAX];
void dfs(int u, int p = -1, int d = 0)
{
    color[u] = d;
    for (auto [v, c] : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u, (d + c) % 2);
    }
}
int main(void)
{
    int u, v, c;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> c, --u, --v;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    dfs(0);
    for_each(color, color + n, [](int x) { cout << x << endl; });
    return 0;
}

{% endraw %}
```
