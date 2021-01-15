/** @file
 * @date                2021-01-11
 * @url                 https://codeforces.com/contest/1281/problem/E
 * @tags                greedy, dfs, trees
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/72212).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Graph = vector<vector<ii>>;

pair<ll, ll> solve(Graph g)
{
    int        n = g.size();
    vector<ll> sz(n, 1), dp1(n, 0), dp2(n, 0);

    function<void(int, int)> dfs;

    dfs = [&](int u, int p) {
        for (auto [v, w] : g[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            sz[u] += sz[v];
            dp1[u] += dp1[v] + (sz[v] & 1 ? w : 0);
            dp2[v] = min(sz[v], n - sz[v]) * w;
        }
    };
    dfs(0, 0);

    return {dp1[0], accumulate(all(dp2), 0LL)};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        Graph g(2 * k);
        for (int i = 0; i < 2 * k - 1; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w, u--, v--;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        auto [G, B] = solve(g);
        cout << G << " " << B << endl;
    }
    return 0;
}
