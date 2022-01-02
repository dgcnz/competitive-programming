#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/graph/toposort>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    UndirectedGraph g(n), gi(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g.add_edge(u, v);
        gi.add_edge(v, u);
    }

    int const   INF   = 1e9;
    vector<int> order = toposort(g, 0);
    vector<int> dp(n, -INF), prv(n);
    dp[0] = 0, prv[0] = 0;
    if (order.empty() or count(all(order), n - 1) == 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (auto v : order)
            for (auto u : gi[v])
                if (dp[u] + 1 > dp[v])
                    dp[v] = dp[u] + 1, prv[v] = u;

        cout << dp[n - 1] + 1 << endl;

        vector<int> ans;
        int         u = n - 1;
        do
        {
            ans.push_back(u);
            u = prv[u];
        } while (prv[u] != u);
        ans.push_back(u);
        reverse(all(ans));
        increment(all(ans));
        write(all(ans), " "), cout << endl;
    }

    return 0;
}
