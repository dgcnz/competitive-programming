---
layout: post
title: 1688 Company Queries Ii
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
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
int const BITS = sizeof(int) * 8;
int n, timer, tin[NMAX], tout[NMAX], up[NMAX][LMAX];
vi g[NMAX];
void dfs(int u, int p)
{
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LMAX; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != p)
            dfs(v, u);
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
    for (int i = 2; i <= n; ++i)
    {
        int ei;
        cin >> ei;
        g[ei].push_back(i);
        g[i].push_back(ei);
    }
    dfs(1, 1);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}

```
