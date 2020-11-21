---
layout: post
mathjax: true
title: 1136 Counting Paths
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
int n, timer, val[NMAX], tin[NMAX], tout[NMAX], up[NMAX][LMAX], ans[NMAX];
vi g[NMAX];
void preprocess(int u, int p)
{
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LMAX; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : g[u])
        if (v != p)
            preprocess(v, u);
    tout[u] = ++timer;
}
void solve(int u, int p)
{
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        solve(v, u);
        val[u] += val[v];
    }
    ans[u] = val[u];
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LMAX - 1; i >= 0; --i)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root = 1;
    preprocess(root, root);
    while (m--)
    {
        int u, v, l;
        cin >> u >> v;
        val[u] += 1;
        val[v] += 1;
        l = lca(u, v);
        val[l] -= 1;
        if (l != root)
            val[up[l][0]] -= 1;
    }
    solve(1, 1);
    write(ans + 1, ans + n + 1, " "), cout << endl;
    return 0;
}

{% endraw %}
```
