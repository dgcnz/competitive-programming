#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vector<vi> compress_graph(vector<vi> g, vi color)
{
    int          n = g.size();
    atcoder::dsu dsu(n);
    for (int u = 0; u < n; ++u)
        for (auto v : g[u])
            if (color[u] == color[v])
                dsu.merge(u, v);

    auto       components = dsu.groups();
    int        m          = components.size();
    vector<vi> gc(m);

    vector<int> id(n);
    for (int ix = 0; ix < m; ++ix)
        for (auto u : components[ix])
            id[u] = ix;

    set<ii> edges;
    for (int u = 0; u < n; ++u)
    {
        for (auto v : g[u])
        {
            if (color[u] != color[v])
            {
                auto uid = id[dsu.leader(u)], vid = id[dsu.leader(v)];
                edges.emplace(uid, vid);
                edges.emplace(vid, uid);
            }
        }
    }

    for (auto [u, v] : edges)
        gc[u].push_back(v);
    return gc;
}

int compute_diameter(vector<vi> g)
{

    int maxd     = 0;
    int endpoint = 0;

    function<void(int, int, int)> dfs = [&](int u, int p, int d)
    {
        if (d > maxd)
        {
            maxd     = d;
            endpoint = u;
        }
        for (auto v : g[u])
            if (v != p)
                dfs(v, u, d + 1);
    };

    dfs(0, 0, 0);

    int a = endpoint;
    maxd  = 0;
    dfs(a, a, 0);
    return maxd;
}

int solve(vector<vi> g, vi color)
{
    auto new_g = compress_graph(g, color);
    auto d     = compute_diameter(new_g);
    return (d + 1) / 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi color(n);
    read(all(color));
    vector<vi> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << solve(g, color) << endl;
    return 0;
}
