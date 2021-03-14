/** @file
 * @date                2021-03-14
 * @url                 https://atcoder.jp/contests/abc120/tasks/abc120_d
 * @tags                observation, graphs
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Checking how many nodes an edge disconnects is essentially the same as
 * checking how many nodes it connects if the order of placement were reversed.
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
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vector<ll> solve(int n, vector<ii> edges)
{
    int        m = edges.size();
    dsu        g(n);
    vector<ll> ans(m);
    ans[0] = (n * ll(n - 1)) / 2;
    reverse(all(edges));
    for (int i = 0; i < m - 1; ++i)
    {
        auto [u, v] = edges[i];
        ll new_conn = 0;
        if (!g.same(u, v))
            new_conn = (ll)g.size(u) * g.size(v);
        ans[i + 1] = ans[i] - new_conn;
        g.merge(u, v);
    }
    reverse(all(ans));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ii> edges(m);
    for (auto &[u, v] : edges)
        cin >> u >> v, u--, v--;
    auto ans = solve(n, edges);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}
