---
layout: post
mathjax: true
title: 691D Swaps In Permutation
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
struct dsu
{
    int n;
    vi parent;
    vi sz;
    dsu(int n) : n(n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            sz[i] = 0;
        }
    }
    void merge_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
    int find_set(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find_set(parent[u]);
    }
};
int main(void)
{
    int n, m, u, v;
    vi p;
    cin >> n >> m;
    p.resize(n);
    dsu d(n);
    for (auto &pi : p)
        cin >> pi;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v, u--, v--;
        d.merge_set(u, v);
    }
    vector<set<int, greater<int>>> sorted(n);
    for (int i = 0; i < n; ++i)
        sorted[d.find_set(i)].insert(p[i]);
    for (int i = 0; i < n; ++i)
    {
        int p = d.find_set(i);
        cout << *sorted[p].begin() << " ";
        sorted[p].erase(sorted[p].begin());
    }
    return 0;
}

{% endraw %}
```