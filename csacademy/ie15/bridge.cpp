#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int iceil(int a, int b) { return (a + b - 1) / b; }

pair<int, int> get_center(Graph<void> &g)
{
    int         n = g.size();
    vector<int> p(n, -1);

    function<ii(int, int)> dfs = [&](int u, int d)
    {
        ii ans = {d, u};
        for (auto v : g[u])
        {
            if (v == p[u])
                continue;
            p[v] = u;
            ans  = max(ans, dfs(v, d + 1));
        }
        return ans;
    };

    auto l = dfs(0, 0);
    fill(all(p), -1);
    auto r = dfs(l.second, 0);

    int diameter = r.first;
    int u        = r.second;
    for (int i = 0; i < diameter / 2; ++i)
        u = p[u];

    return {u, diameter};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n1;
        cin >> n1;
        Graph<void> g1(n1);

        for (int i = 0; i < n1 - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g1.add_undirected_edge(u, v);
        }

        int n2;
        cin >> n2;
        Graph<void> g2(n2);

        for (int i = 0; i < n2 - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g2.add_undirected_edge(u, v);
        }

        auto [c1, d1] = get_center(g1);
        auto [c2, d2] = get_center(g2);

        auto d = max({d1, d2, 1 + iceil(d1, 2) + iceil(d2, 2)});
        cout << d << endl;
        cout << c1 + 1 << " " << c2 + 1 << endl;
    }
    return 0;
}
