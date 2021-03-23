#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(vector<vector<ll>> dist)
{
    int                         n = dist.size();
    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == j and dist[i][j] != 0)
                return false;
            if (i != j and dist[i][j] != dist[j][i])
                return false;
            if (i != j and dist[i][j] == 0)
                return false;
            if (i != j)
                edges.emplace_back(dist[i][j], i, j);
        }
    }

    sort(all(edges));

    atcoder::dsu        dsu(n);
    vector<vector<ll>>  d2(n, vector<ll>(n, 0));
    vector<vector<int>> g(n);
    for (auto [d, u, v] : edges)
    {
        if (not dsu.same(u, v))
        {
            dsu.merge(u, v);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            d2[u][v] = d2[v][u] = d;
        }
    }

    function<bool(int, int, int)> dfs = [&](int src, int u, int p) {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (dist[v][src] != (d2[v][src] = d2[u][src] + d2[u][v]))
                return false;
            if (not dfs(src, v, u))
                return false;
        }
        return true;
    };

    for (int u = 0; u < n; ++u)
        if (not dfs(u, u, -1))
            return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<vector<ll>> dist(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    cout << (solve(dist) ? "YES" : "NO") << endl;
    return 0;
}
