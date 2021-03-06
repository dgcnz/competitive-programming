#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using iii = array<int, 3>;
using vi  = vector<int>;

int const NMAX = 200 + 11;

int        n;
vi         g[NMAX];
vector<ii> edges;
ii         forbidden_edge;

bool is_forbidden(int u, int v)
{
    auto [up, vp] = forbidden_edge;
    return (u == up and v == vp) or (u == vp and v == up);
}

ii furthest_node(int u, int p, int d)
{
    ii ans = {d, u};
    for (int v : g[u])
    {
        if (v == p or is_forbidden(u, v))
            continue;
        ans = max(ans, furthest_node(v, u, d + 1));
    }

    return ans;
}

int find_diameter(int root)
{
    auto [d1, u] = furthest_node(root, -1, 0);
    auto [d2, v] = furthest_node(u, -1, 0);
    return d2;
}

int main(void)
{
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u, v};
    }

    int ans = 0;
    for (auto [u, v] : edges)
    {
        forbidden_edge = {u, v};
        int a = find_diameter(u), b = find_diameter(v);
        ans = max(ans, a * b);
    }

    cout << ans << endl;

    return 0;
}
