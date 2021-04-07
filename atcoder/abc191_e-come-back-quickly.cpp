#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/dijkstra>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

vi solve(int n, vector<iii> edges)
{
    int const          INF = 1e8;
    Dijkstra<int>      sssp(n);
    vector<vector<ii>> gc(n);
    vector<int>        ans(n, INF);
    for (auto [u, v, c] : edges)
    {
        sssp.add_edge(u, v, c);
        gc[v].emplace_back(u, c);
    }

    for (int u = 0; u < n; ++u)
    {
        sssp(u);
        for (auto [v, c] : gc[u])
            if (sssp.is_reachable(v))
                ans[u] = min(ans[u], c + sssp.distance(v));
        if (ans[u] == INF)
            ans[u] = -1;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<iii> edges(m);
    for (auto &[u, v, c] : edges)
        cin >> u >> v >> c, u--, v--;

    auto ans = solve(n, edges);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}
