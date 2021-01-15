/** @file
 * @date                2021-01-14
 * @url                 https://codeforces.com/contest/1473/problem/D
 * @tags                segment_tree, data_structures
 * @status              AC
 * @score               4
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         15
 * @time_complexity     O(m \log{n})
 * @memory_complexity   O(n)
 * @idea
 * For a given query $(l, r)$, we are dividing the string into three parts:
 * - left: $(1, l - 1)$
 * - mid: $(l, r)$
 * - right: $(r + 1, n)$
 *
 * Note that removing mid will essentially decrease right by the net change in
 * mid.
 *
 * Furthermore, note that for any range $l, r$, we may know the number of unique
 * elements in that range by finding the maximum and minimum on that range
 * (since every movement either increases or decreases by 1).
 *
 * This suggests a data structure problem we can solve using segment tree.
 *
 * For each range, store the maximum, minimum and the net change and query the
 * three ranges described beforehand.
 *
 * Reverse the net change of the mid range to the right range (by subtracting it
 * from right's min and max).
 *
 * Finally, merge the left range with the right range if they overlap, otherwise
 * count them separately. If they don't contain $0$ increase the answer by $1$.
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
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using pll = pair<ll, ll>;

ll const INF = 1e15;

struct S
{
    ll mn, mx, delta;
};

S op(S a, S b) { return {min(a.mn, b.mn), max(a.mx, b.mx), a.delta + b.delta}; }

S e() { return {INF, -INF, 0}; };

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        using SegmentTree = atcoder::segtree<S, op, e>;
        vector<S> a(n);

        int cur = 0, delta;
        for (int i = 0; i < n; ++i)
        {
            delta = (s[i] == '+' ? +1 : -1);
            cur += delta;
            a[i] = {cur, cur, delta};
        }

        SegmentTree st(a);

        auto intersect = [](pll a, pll b) {
            if (a.first > b.first)
                swap(a, b);
            return a.second >= b.first;
        };

        while (m--)
        {
            int l, r;
            cin >> l >> r, l--;

            S left = st.prod(0, l), mid = st.prod(l, r), right = st.prod(r, n);

            vector<pll> intervals;
            if (left.mn != INF)
                intervals.emplace_back(left.mn, left.mx);
            if (right.mn != INF)
                intervals.emplace_back(right.mn - mid.delta,
                                       right.mx - mid.delta);

            ll ans = 0;
            if (none_of(all(intervals),
                        [](ii lr) { return lr.first <= 0 and 0 <= lr.second; }))
                ans += 1;

            if (intervals.size() == 2 and intersect(intervals[0], intervals[1]))
            {
                intervals[0] = {min(intervals[0].first, intervals[1].first),
                                max(intervals[0].second, intervals[1].second)};
                intervals.pop_back();
            }
            for (auto [ll, rr] : intervals)
                ans += rr - ll + 1;
            cout << ans << endl;
        }
    }
    return 0;
}
