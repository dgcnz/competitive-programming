---
layout: post
mathjax: true
title: 1406C Link Cut Centroids
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
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 1e5 + 11;
int n, sz[NMAX];
vi g[NMAX];
void calc_sz(int u, int p)
{
    sz[u] = 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        calc_sz(v, u);
        sz[u] += sz[v];
    }
}
int find_centroid(int u, int p, int n)
{
    for (auto v : g[u])
        if (v != p and sz[v] > n / 2)
            return find_centroid(v, u, n);
    return u;
}
ii find_leaf(int u, int p)
{
    int vmax = 0;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        if (sz[v] > sz[vmax])
            vmax = v;
    }
    if (vmax == 0)
        return {p, u};
    return find_leaf(vmax, u);
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(sz, 0, sizeof sz);
        for (int i = 0; i < NMAX; ++i)
            g[i].clear();
        cin >> n;
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int root = 1;
        calc_sz(root, -1);
        root = find_centroid(root, -1, n);
        memset(sz, 0, sizeof sz);
        calc_sz(root, -1);
        auto [u, v] = find_leaf(root, -1);
        cout << u << " " << v << endl;
        cout << root << " " << v << endl;
    }
    return 0;
}

{% endraw %}
```
