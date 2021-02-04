/** @file
 * @date                2021-02-03
 * @url                 https://www.spoj.com/problems/PT07Y/
 * @tags                trees, graphs
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Test first if graph's edges is $n - 1$, then check if it is connected.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Graph = vector<vi>;

bool solve(int n, vector<ii> edges)
{
    edges.erase(unique(all(edges)), end(edges));
    if ((int)edges.size() != n - 1)
        return false;
    atcoder::dsu dsu(n);
    for (auto [u, v] : edges)
        dsu.merge(u, v);
    return dsu.size(0) == n;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ii> edges(m);
    for (auto &[u, v] : edges)
        cin >> u >> v, u--, v--;

    cout << (solve(n, edges) ? "YES" : "NO") << endl;
    return 0;
}
