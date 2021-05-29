#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(vector<vi> g, vector<ll> p, vector<ll> h, ll m)
{
    int        n    = g.size();
    bool       flag = true;
    vector<ll> flux(n, 0), good(n, 0), bad(n, 0);

    function<ll(int, int)> dfs = [&](int u, int parent) {
        flux[u] = p[u];
        ll gsum = 0, bsum = 0;
        for (auto v : g[u])
        {
            if (v != parent)
            {
                flux[u] += dfs(v, u);
                gsum += good[v], bsum += bad[v];
            }
        }

        if (h[u] + flux[u] < 0 or ((h[u] + flux[u]) % 2))
            flag = false;
        good[u] = (h[u] + flux[u]) / 2, bad[u] = flux[u] - good[u];
        if (good[u] > flux[u] or good[u] < 0 or bad[u] > flux[u] or
            bad[u] < 0 or good[u] + bad[u] != flux[u])
            flag = false;

        ll remgood = good[u] - gsum;
        ll rembad  = remgood + bad[u] - bsum;
        if (remgood < 0 or rembad != p[u])
            flag = false;

        return flux[u];
    };
    dfs(0, -1);
    // dbg(flux, good, bad);
    return flag and flux[0] == m ? "YES" : "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> p(n), h(n);
        read(all(p));
        read(all(h));

        vector<vi> g(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cout << solve(g, p, h, m) << endl;
    }
    return 0;
}
