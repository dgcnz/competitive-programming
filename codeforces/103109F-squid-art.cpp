#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#include <cplib/math/utils>
#include <cplib/utils/grid>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

// https://mbit.mbhs.edu/archive/2021s/solutions/SquidArt.cpp

pair<vector<vi>, vi> make_graph(vector<string> const &table)
{
    int          n = table.size(), m = table.back().size();
    atcoder::dsu dsu(n * m);
    auto         id = [n, m](ii x) { return x.first * m + x.second; };

    array<vector<Direction>, 2> directions;
    directions[0] = {LEFT, RIGHT, UP, DOWN, {-1, 1}, {1, 1}};
    directions[1] = {LEFT, RIGHT, UP, DOWN, {-1, -1}, {1, -1}};

    auto in_range = [&](ii u)
    { return 0 <= u.first and u.first < n and 0 <= u.second and u.second < m; };

    auto same = [&](ii u, ii v)
    { return table[u.first][u.second] == table[v.first][v.second]; };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            auto u = ii{i, j};
            for (auto dir : directions[i % 2])
            {
                auto v = u + dir;
                if (in_range(v) and same(u, v))
                    dsu.merge(id(u), id(v));
            }
        }
    }

    set<ii>     edges;
    auto        components = dsu.groups();
    int         k          = components.size();
    vi          colors(k);
    vector<int> cid(n * m, -1);
    for (int ix = 0; ix < k; ++ix)
    {
        int x      = components[ix].back();
        colors[ix] = table[x / m][x % m] - '0';
        for (auto u : components[ix])
            cid[u] = ix;
    }

    vector<vector<int>> g(k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            auto u = ii{i, j};
            for (auto dir : directions[i % 2])
            {
                auto v = u + dir;
                if (in_range(v) and not same(u, v))
                {
                    auto a = dsu.leader(id(u)), b = dsu.leader(id(v));
                    if (edges.find({a, b}) == edges.end())
                    {
                        edges.emplace(a, b), edges.emplace(b, a);
                        g[cid[a]].push_back(cid[b]);
                        g[cid[b]].push_back(cid[a]);
                    }
                }
            }
        }
    }
    return {g, colors};
}

int find_diameter(vector<vi> const &g, vector<int> const &colors)
{
    int k = g.size();

    vi vis(k, 0);

    int mx = 0, a = 0, b = 0;

    function<void(int, int)> dfs1 = [&](int x, int d)
    {
        vis[x] = 1;
        if (d > mx and colors[x] == 0)
        {
            a  = x;
            mx = d;
        }
        for (auto y : g[x])
        {
            if (!vis[y])
                dfs1(y, d + 1);
        }
    };
    function<void(int, int)> dfs2 = [&](int x, int d)
    {
        vis[x] = 1;
        if (d > mx)
        {
            b  = x;
            mx = d;
        }
        for (auto y : g[x])
            if (!vis[y])
                dfs2(y, d + 1);
    };
    dfs1(0, 0);
    fill(all(vis), 0);
    mx = 0;
    dfs2(a, 0);

    return mx;
}

int solve(vector<string> table)
{

    auto [g, colors] = make_graph(table);
    int d            = find_diameter(g, colors);

    return d / 2 + 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    read(all(table));

    cout << solve(table) << endl;
    return 0;
}
