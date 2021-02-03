/** @file
 * @date                2021-02-02
 * @url                 https://www.spoj.com/problems/PT07Z/
 * @tags                dfs, standard
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         10
 * @time_complexity     O(n + m)
 * @memory_complexity   O(n + m)
 * @idea
 * Standard diameter calculation using 2 dfs.
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

int solve(Graph g)
{
    ii                            diameter = {0, 0};
    function<void(int, int, int)> dfs      = [&](int u, int p, int d) {
        for (auto v : g[u])
            if (v != p)
                dfs(v, u, d + 1);
        diameter = max(diameter, {d, u});
    };

    dfs(0, -1, 0);
    dfs(diameter.second, -1, 0);
    return diameter.first;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    Graph g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << solve(g) << endl;
    return 0;
}
