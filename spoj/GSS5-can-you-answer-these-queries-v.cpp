/** @file
 * @date                2020-12-22
 * @url                 https://www.spoj.com/problems/GSS5/
 * @tags                data_structures, segment_tree
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Assume `[x1, y1]` and `[x2, y2]` are non-overlapping ranges.
 * The answer will be the maximum suffix of `[x1, y1]`, plus the total sum of
 * range `]y1, x2[`, plus the maximum prefix of `[x2, y2]`. Computing maximum
 * subarrays on ranges is a well known technique described in
 * [CP-Algorithms](https://cp-algorithms.com/data_structures/segment_tree.html).
 *
 * Handling overlapping ranges, requires a bit of casework:
 * - Best suffix of `[x1, y1]` + best prefix of `]y1, y2]`
 * - Best suffix of `[x1, x2[` + best prefix of `[x2, y2]`
 * - Best subarray in `[x2, y1]`
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll      = long long;
using ii      = pair<int, int>;
using vi      = vector<int>;
int const INF = 1e7;

struct Node
{
    int pre, suf, tot, best;
    Node(int x = 0) : pre(x), suf(x), tot(x), best(x) {}
};

Node merge(Node a, Node b)
{
    Node ans;
    ans.pre  = max(a.pre, a.tot + b.pre);
    ans.suf  = max(b.suf, b.tot + a.suf);
    ans.tot  = a.tot + b.tot;
    ans.best = max({a.best, b.best, a.suf + b.pre});
    return ans;
}

Node e()
{
    Node ans(-INF);
    ans.tot = 0;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n;

        vector<Node> a(n);
        for (auto &ai : a)
        {
            int x;
            cin >> x;
            ai = Node(x);
        }

        atcoder::segtree<Node, merge, e> st(a);
        cin >> q;
        while (q--)
        {
            int x1, y1, x2, y2, ans;
            cin >> x1 >> y1 >> x2 >> y2, x1--, y1--, x2--, y2--;
            if (y1 < x2) // no overlap
                ans = st.prod(x1, y1 + 1).suf + st.prod(y1 + 1, x2).tot +
                      st.prod(x2, y2 + 1).pre;
            else
                ans = max(
                    {st.prod(x2, y1 + 1).best,
                     st.prod(x1, x2).suf + st.prod(x2, y2 + 1).pre,
                     st.prod(x2, y1 + 1).suf + st.prod(y1 + 1, y2 + 1).pre});
            cout << ans << endl;
        }
    }

    return 0;
}
