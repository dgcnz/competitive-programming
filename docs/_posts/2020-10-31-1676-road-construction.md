---
layout: post
mathjax: true
title: 1676 Road Construction
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
using iii = array<int, 3>;
using vi = vector<int>;
struct dsu
{
    int n, nc, lc;
    vi parent, sz;
    dsu(int n)
    {
        nc = n;
        lc = 0;
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
            nc -= 1;
            lc = max(lc, sz[u]);
        }
    }
};
int main(void)
{
    int n, m, u, v;
    cin >> n >> m;
    dsu d(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v, --u, --v;
        d.union_set(u, v);
        cout << d.nc << " " << d.lc << endl;
    }
    return 0;
}

{% endraw %}
```