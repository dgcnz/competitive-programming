/** @file
 * @date                2021-03-06
 * @url                 https://atcoder.jp/contests/abc194/tasks/abc194_e
 * @tags                segment_tree, data_structures, mex
 * @status              AC
 * @score               4
 * @difficulty          4
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 *
 * Having seen the first $k$ elements in the array, say that `last(x)` returns
 * the last position where $x$ was seen and $-1$ otherwise.
 *
 * If we've seen the elements up to index $i + m$, note that finding the mex of
 * array `a[i + 1, i + m]`, is equivalent to finding the first $y$ such that
 * $last(y) \geq i$. That is the first value that isn't in the range
 * `[i + 1, i + m]`.
 *
 * To compute such number, we can use a segment tree for range min queries on
 * the $last$ array and perform binary search to find the first $r$ such that
 * `min(last[1], last[2], ..., last[r - 1]) > i` and
 * `min(last[1], last[2], ..., last[r - 1], last[r]) <= i`, i.e the first $r$
 * such that $last(r) \geq i$.
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
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return 1e9; }

int solve(vi a, int m)
{
    int n = a.size(), ans = 1e9;

    segtree<S, op, e> rmq(n);
    for (int i = 0; i < n; ++i)
        rmq.set(i, -1);
    for (int i = 0; i < n; ++i)
    {
        rmq.set(a[i], i);
        if (i >= m - 1)
        {
            int  target = i - m + 1;
            auto f      = [target](S x) { return x >= target; };
            ans         = min(ans, rmq.max_right(0, f));
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << solve(a, m) << endl;
    return 0;
}
