/** @file
 * @date                2021-01-15
 * @url                 https://codeforces.com/problemset/problem/61/E
 * @tags                data_structures, segment_tree
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * For each element $a_k$ we can know how many times it contributes to the
 * weakness of the overall army if we can support the following range query:
 *
 * - `inv(l, r)`: Number of inversions with $a_i > a_j$ such that
 *   $l \leq a_j \leq r$.
 *
 * To compute such value, we can use this additional function:
 * - `freq(l, r)`: Number of elements $l \leq a_i \leq r$.
 *
 * For each element from the left to right, we'll do the following:
 *
 * 1. We'll increase our overall answer by querying for `inv(ai + 1, amax)`.
 * 2. We'll increase the inverse count of $a_i$ by `freq(ai + 1, amax)`, i.e.
 the number of elements greater than $a_i$ seen so far.
 * 3. We'll increase the occurrence of $a_i$ in `freq` by 1.
 *
 * Any range query data structure should do the job (I'm using AtCoder's Segment
 Tree), as long as you compress the numbers.
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

template <typename T>
map<T, int> compress(vector<T> values)
{
    map<T, int> mp;
    int         cnt = 0;
    for (auto v : values)
        mp[v];
    for (auto &[k, v] : mp)
        v = cnt++;
    return mp;
}

using S = ll;
S e() { return 0; }
S op(S a, S b) { return a + b; }

ll solve(vi a)
{
    using RangeSumQuery = atcoder::segtree<S, op, e>;

    auto          id  = compress(a);
    int           n   = isz(id) + 1;
    ll            ans = 0;
    RangeSumQuery freq(n), inv(n);
    for (auto &ai : a)
    {
        ai            = id[ai];
        ll inversions = freq.prod(ai + 1, n);
        ans += inv.prod(ai + 1, n);
        inv.set(ai, inv.get(ai) + inversions);
        freq.set(ai, freq.get(ai) + 1);
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
