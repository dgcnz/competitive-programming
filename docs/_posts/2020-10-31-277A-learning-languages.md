---
layout: post
mathjax: true
title: 277A Learning Languages
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
int n, m;
int parent[2 * 110];
int siz[2 * 110];
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}
int find_set(int v)
{
    if (parent[v] == v)
        return v;
    return find_set(parent[v]);
}
void union_sets(int u, int v)
{
    u = find_set(u);
    v = find_set(v);
    if (u != v)
    {
        parent[v] = u;
        siz[u] += siz[v];
    }
}
int main(void)
{
    int ki, aij, count = 0;
    bool isolated = true;
    cin >> n >> m;
    for (int i = 0, len = n + m; i < len; ++i)
        make_set(i);
    for (int i = 0; i < n; ++i)
    {
        cin >> ki;
        while (ki--)
        {
            cin >> aij;
            union_sets(i, aij - 1 + n);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (siz[i] != 1)
            isolated = false;
        if (parent[i] == i)
            ++count;
    }
    cout << count - not(isolated) << endl;
    return 0;
}

{% endraw %}
```
