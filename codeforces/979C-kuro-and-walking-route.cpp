/** @file
 * @date                2021-02-02
 * @url                 https://codeforces.com/problemset/problem/979/C
 * @tags                dfs, graphs
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         15
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * We can rephrase the task of finding all paths that don't cross $x$ first and
 * $y$ second as all the possible paths minus the paths that do cross $x$ first
 * and $y$ second.
 *
 *
 * The latter can be found by multiplying the size of the subtrees of $x$ and $y
 * that don't intersect one another.
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
using Graph = vector<vi>;

ll solve(Graph g, int x, int y)
{
    int         n = g.size();
    vector<int> sz(n, 1), p(n, -1);

    function<void(int)> dfs = [&](int u) {
        for (auto v : g[u])
        {
            if (v != p[u])
            {
                p[v] = u;
                dfs(v);
                sz[u] += sz[v];
            }
        }
    };

    dfs(x);
    int vy = y;
    while (p[vy] != x)
        vy = p[vy];

    ll prohibited = 1;
    for (auto v : g[x])
        if (v != vy)
            prohibited += sz[v];
    prohibited *= sz[y];
    return n * ll(n - 1) - prohibited;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y, x--, y--;

    Graph g(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << solve(g, x, y) << endl;

    return 0;
}
