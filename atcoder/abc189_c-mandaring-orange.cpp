/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc189/tasks/abc189_c
 * @tags                greedy, segment_tree, binary_search, brute_force
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * For each element $a_i$, find indexes $l$ and $r$, such that $l \leq i \leq r$
 * and $\min{a_l,...,a_i,...,a_r} = a_i$. The answer for such particular index
 * would then be $a_i \times (r - l + 1)$.
 *
 * There are several ways to do this, check
 * [Editorial](https://atcoder.jp/contests/abc189/editorial/592) for more info.
 *
 * In my approach, I used a segment tree to handle minimum range queries and
 * then used binary search on it to find both indexes. Check AtCoder's
 * SegmentTree's
 * [docs](https://atcoder.github.io/ac-library/master/document_en/segtree.html)
 * and this [problem](https://atcoder.jp/contests/practice2/tasks/practice2_j)
 * for an idea of how `min_left` and `max_right` work.
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = int;
int op(int a, int b) { return min(a, b); }
int e() { return 1e9; }

ll solve(vi a)
{
    int n   = isz(a);
    ll  ans = 0;

    using RMQ = atcoder::segtree<S, op, e>;

    RMQ st(a);
    for (int i = 0; i < n; ++i)
    {
        int  ai = a[i];
        auto f  = [ai](S b) { return ai <= b; };

        int l = st.min_left(i, f);
        int r = st.max_right(i, f);
        ans   = max(ans, a[i] * ll(r - l));
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n);

    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    return 0;
}
