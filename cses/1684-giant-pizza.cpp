#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 2e5 + 11;

int  n, m, cur_comp, comp[NMAX];
bool vis[NMAX], ans[NMAX];
vi   g[NMAX], gi[NMAX], order;

inline int id(int u, char c) { return 2 * u + (c != '+'); }
inline int neg(int u) { return u ^ 1; }

void dfs1(int u)
{
    vis[u] = true;
    for (auto v : g[u])
        if (not vis[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u)
{
    comp[u] = cur_comp;
    for (auto v : gi[u])
        if (not comp[v])
            dfs2(v);
}

bool solve(void)
{
    for (int u = 0; u < 2 * n; ++u)
        if (not vis[u])
            dfs1(u);

    for_each(order.rbegin(), order.rend(), [](int u) {
        if (not comp[u])
            ++cur_comp, ::dfs2(u);
    });

    for (int u = 0; u < 2 * n; u += 2)
    {
        if (comp[u] == comp[u + 1])
            return false;
        ans[u / 2] = comp[u] > comp[u + 1];
    }

    return true;
}

int main(void)
{
    char c1, c2;
    int  u, v;

    cin >> m >> n;

    for (int i = 0; i < m; ++i)
    {
        cin >> c1 >> u >> c2 >> v, u--, v--;
        u = id(u, c1), v = id(v, c2);
        g[neg(u)].push_back(v);
        g[neg(v)].push_back(u);

        gi[v].push_back(neg(u));
        gi[u].push_back(neg(v));
    }

    if (solve())
        for_each(ans, ans + n, [](bool x) { cout << (x ? '+' : '-') << " "; }),
            cout << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
