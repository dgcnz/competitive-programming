/** @file
 * @date                2021-01-30
 * @url                 https://cses.fi/problemset/task/2134
 * @tags                data_structures, trees, hld, segment_tree
 * @status              AC
 * @score               3
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         3
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Same as problem Path Queries but with maximum as the segment tree operation.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/graphs/hld>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vi val(n);
    for (auto &x : val)
        cin >> x;

    HLD<atcoder::segtree, S, op, e> hld(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        hld.add_edge(u, v);
    }

    hld();

    for (int u = 0; u < n; ++u)
        hld.set(u, val[u]);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, x;
            cin >> u >> x, u--;
            hld.set(u, x);
        }
        else
        {
            int u, v;
            cin >> u >> v, u--, v--;
            cout << hld.query(u, v) << " ";
        }
    }
    cout << endl;

    return 0;
}
