/** @file
 * @date                2021-02-02
 * @url                 https://codeforces.com/contest/1093/problem/D
 * @tags                dfs, graphs, bicoloring
 * @status              AC
 * @score               2
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         60
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/63877)
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint998244353;

ll solve(int n, vector<ii> edges)
{
    using Graph = vector<vector<int>>;

    Graph g(n);
    for (auto [u, v] : edges)
        g[u].push_back(v), g[v].push_back(u);

    mint         ans = 1;
    vector<bool> vis(n, 0), color(n, 0);
    for (int u = 0; u < n; ++u)
    {
        if (!vis[u])
        {
            vector<int>         component;
            function<bool(int)> dfs = [&](int u) {
                vis[u] = true;
                for (auto v : g[u])
                {
                    if (vis[v] and color[v] == color[u])
                        return false;
                    else if (vis[v])
                        continue;
                    color[v] = !color[u];
                    if (not dfs(v))
                        return false;
                }
                component.push_back(u);
                return true;
            };
            if (not dfs(u))
                return 0;

            int k = count_if(all(component), [&](int u) { return color[u]; });
            ans *= mint(2).pow(k) + mint(2).pow(isz(component) - k);
        }
    }
    return ans.val();
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
        vector<ii> edges(m);
        for (auto &[u, v] : edges)
            cin >> u >> v, u--, v--;
        cout << solve(n, edges) << endl;
    }
    return 0;
}
