/** @file
 * @date                2020-12-23
 * @url                 https://www.spoj.com/problems/LITE/
 * @tags                data_structures, segment_tree, lazy
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         15
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Choose your favorite range-update, range-query data structure. I'll be using
 * AtCoder's Lazy Segment Tree for this.
 *
 * Let's store for each segtree node the amount of elements is covering in its
 * respective range, $n$ and the amount of lights set "on", $setcnt$.
 *
 * A range-update (switching lights), $(l, r)$, would be equal to turning off
 * all set lights and vice versa, or $setcnt = n - setcnt$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/lazysegtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct S
{
    int n, set_cnt;
};

S op(S a, S b) { return {a.n + b.n, a.set_cnt + b.set_cnt}; }

S e() { return {0, 0}; }

using F = bool;

S mapping(F f, S x) { return (f ? S{x.n, x.n - x.set_cnt} : x); }

F composition(F f, F g) { return f ^ g; }

F id() { return 0; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<S> a(n);
    for (auto &ai : a)
        ai = S{1, 0};

    using namespace atcoder;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r, l--, r--;
        if (type == 0)
            seg.apply(l, r + 1, true);
        else
        {
            auto x = seg.prod(l, r + 1);
            cout << x.set_cnt << endl;
        }
    }
    return 0;
}
