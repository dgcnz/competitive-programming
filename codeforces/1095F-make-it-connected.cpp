/** @file
 * @date                2021-02-02
 * @url                 https://codeforces.com/problemset/problem/1095/F
 * @tags                minimum_spanning_tree, dsu, greedy
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * If there were no special offers the optimal answer would be all vertices
 * connected to the one with least cost. Let's try to improve that.
 *
 * Build a graph composed of special offer edges and edges to the minimum vertex
 * and apply minimum spanning tree.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <bits/stdc++.h>
#include <cplib/graphs/kruskal>

#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll           = long long;
using ii           = pair<int, int>;
using vi           = vector<int>;
using WeightedEdge = tuple<int, int, ll>;

ll solve(vector<ll> a, vector<WeightedEdge> edges)
{
    int         n = a.size();
    Kruskal<ll> mst(n);
    for (auto [u, v, w] : edges)
        mst.add_edge(u, v, w);

    int root = distance(begin(a), min_element(all(a)));
    for (int u = 0; u < n; ++u)
        if (u != root)
            mst.add_edge(u, root, a[u] + a[root]);

    ll   ans       = 0;
    auto mst_edges = mst.run();
    for (auto [u, v, w] : mst_edges)
        ans += w;

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    vector<WeightedEdge> edges(m);
    for (auto &[u, v, w] : edges)
        cin >> u >> v >> w, u--, v--;

    cout << solve(a, edges) << endl;
    return 0;
}
