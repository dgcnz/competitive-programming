#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<ll>;

ll solve(Graph<void> g, vi a, vi b, vi c)
{
    int n = g.size();

    ll                  ans = 0;
    vector<ll>          z(n), o(n), m(n, 1), p(n), mina(n);
    function<void(int)> dfs = [&](int u)
    {
        for (auto v : g[u])
        {
            if (v == p[u])
                continue;
            p[v]    = u;
            mina[v] = min(a[v], mina[u]);
            dfs(v);
            z[u] += z[v];
            o[u] += o[v];
            m[u] += m[v];
        }
        if (b[u] == 0 and c[u] == 1)
            z[u]++;
        else if (b[u] == 1 and c[u] == 0)
            o[u]++;
        ll k = min(z[u], o[u]);
        ans += 2 * k * mina[u];
        z[u] -= k, o[u] -= k;
    };

    mina[0] = a[0];
    p[0]    = 0;
    dfs(0);
    return z[0] or o[0] ? -1 : ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    Graph<void> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g.add_undirected_edge(u, v);
    }

    cout << solve(g, a, b, c) << endl;

    return 0;
}
