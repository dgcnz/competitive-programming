---
layout: post
mathjax: true
title: 1167C News Distribution
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
    vi parent;
    vi sz;
    dsu(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int a)
    {
        if (parent[a] == a)
            return a;
        return (parent[a] = find_set(parent[a]));
    }
    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    int get_size(int a) { return sz[find_set(a)]; }
};
int main(void)
{
    int n, m, ki, a0, a;
    cin >> n >> m;
    dsu cc(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> ki;
        for (int j = 0; j < ki; ++j)
        {
            if (j == 0)
                cin >> a0;
            else
            {
                cin >> a;
                cc.union_set(a0, a);
            }
        }
    }
    for (int a = 1; a <= n; ++a)
    {
        cout << cc.get_size(a) << " ";
    }
    cout << endl;
    return 0;
}

{% endraw %}
```