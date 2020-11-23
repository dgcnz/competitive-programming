---
layout: post
mathjax: true
title: 1135 Distance Queries
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}
int const NMAX = 2e5 + 11;
int const LMAX = 20;
int n, timer, tin[NMAX], tout[NMAX], up[NMAX][LMAX], depth[NMAX];
vi g[NMAX];
void dfs(int u, int p)
{
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LMAX; ++i)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : g[u])
    {
        if (v != p)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LMAX - 1; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << depth[u] + depth[v] - 2 * depth[lca(u, v)] << endl;
    }
    return 0;
}

{% endraw %}
```