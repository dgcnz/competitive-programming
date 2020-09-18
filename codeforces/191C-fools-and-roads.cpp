#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 1e5 + 11;
int const LMAX = 18;

int n, val[NMAX], tin[NMAX], tout[NMAX], up[NMAX][LMAX + 1], ssize[NMAX],
    depth[NMAX], timer;
ii edges[NMAX];
vi g[NMAX];

void precompute_lca(int u, int p)
{
    tin[u]   = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= LMAX; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (auto v : g[u])
        if (v != p)
            precompute_lca(v, u);

    tout[u] = ++timer;
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
    for (int i = LMAX; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void precompute_sz(int u, int p = 0)
{
    ssize[u] = val[u];
    depth[u] = depth[p] + 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        precompute_sz(v, u);
        ssize[u] += ssize[v];
    }
}

int main(void)
{
    int k, u, v, root = 1;

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u, v};
    }
    precompute_lca(root, root);

    cin >> k;
    while (k--)
    {
        cin >> u >> v;
        val[lca(u, v)] -= 2;
        val[u] += 1;
        val[v] += 1;
    }

    precompute_sz(root);

    for (int i = 0; i < n - 1; ++i)
    {
        auto [u, v] = edges[i];
        if (depth[u] < depth[v])
            swap(u, v); // u is always deeper
        cout << ssize[u] << " ";
    }
    cout << endl;

    return 0;
}
