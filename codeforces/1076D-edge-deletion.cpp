#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 3e5 + 11;
ll const  INF  = 1e17;

int           n, m, k;
vector<ii>    g[NMAX];
array<int, 3> edges[NMAX];

void dfs(int u, int parent, int &rem, vector<vi> &spt, vi &p)
{
    p[u] = parent;
    for (auto v : spt[u])
        if (rem > 0)
            dfs(v, u, --rem, spt, p);
}

vi dijkstra(int s)
{
    vector<ll>         d(n + 1, INF);
    vi                 p(n + 1, -1);
    set<pair<ll, int>> q;
    d[s] = 0;
    q.insert({0, s});
    while (!q.empty())
    {
        int u = q.begin()->second;
        q.erase(q.begin());

        for (auto [v, w] : g[u])
        {
            if (d[u] + w < d[v])
            {
                q.erase({d[v], v});
                d[v] = d[u] + w;
                p[v] = u;
                q.insert({d[v], v});
            }
        }
    }
    return p;
}

int main(void)
{
    int u, v, w;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges[i] = {u, v, w};
    }

    auto p = dijkstra(1);

    if (k < n - 1) // need removal
    {
        vector<vi> spt(n + 1);
        for (int v = 1; v <= n; ++v)
        {
            u = p[v];
            if (u != -1)
                spt[u].push_back(v);
        }
        fill(all(p), -1);
        int rem = k;
        dfs(1, -1, rem, spt, p);
    }

    cout << min(k, n - 1) << endl;
    for (int i = 0; i < m; ++i)
    {
        auto [u, v, w] = edges[i];
        if (p[u] == v or p[v] == u)
            cout << i + 1 << " ";
    }

    return 0;
}
