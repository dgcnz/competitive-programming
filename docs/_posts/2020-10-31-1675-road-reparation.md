---
layout: post
title: 1675 Road Reparation
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using iii = array<int, 3>;
using vi = vector<int>;
struct dsu
{
    int n;
    vi parent, sz;
    dsu(int n)
    {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find_set(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find_set(parent[u]);
    }
    void union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            parent[v] = parent[u];
            sz[u] += sz[v];
        }
    }
    bool is_connected(int l, int r)
    {
        int p = find_set(l);
        for (int u = l; u <= r; ++u)
            if (p != find_set(u))
                return false;
        return true;
    }
};
int main(void)
{
    int n, m;
    vector<iii> edges;
    cin >> n >> m;
    edges.resize(m);
    for (auto &[c, u, v] : edges)
        cin >> u >> v >> c;
    sort(edges.begin(), edges.end());
    dsu d(n + 1);
    ll ans = 0;
    for (auto [c, u, v] : edges)
    {
        if (d.find_set(u) == d.find_set(v))
            continue;
        d.union_set(u, v);
        ans += c;
    }
    if (d.is_connected(1, n))
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

{% endraw %}
```
