#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 1e5 + 11;

int  n, m, cur_kingdom, kingdom[NMAX];
bool vis[NMAX];
vi   g[NMAX], gi[NMAX], order;

void toposort(int u)
{
    vis[u] = true;
    for (auto v : g[u])
        if (not vis[v])
            toposort(v);
    order.push_back(u);
}

void buildscc(int u)
{
    vis[u]     = true;
    kingdom[u] = cur_kingdom;
    for (auto v : gi[u])
        if (not vis[v])
            buildscc(v);
}

int main(void)
{
    int u, v;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }

    memset(vis, 0, sizeof(vis));
    for (int u = 1; u <= n; ++u)
        if (not vis[u])
            toposort(u);
    memset(vis, 0, sizeof(vis));
    for_each(order.rbegin(), order.rend(), [](int u) {
        if (not vis[u])
            ++cur_kingdom, buildscc(u);
    });

    cout << cur_kingdom << endl;
    for_each(kingdom + 1, kingdom + n + 1, [](int k) { cout << k << " "; }),
        cout << endl;

    return 0;
}
