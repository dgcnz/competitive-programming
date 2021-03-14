/** @file
 * @date                2021-03-12
 * @url                 https://atcoder.jp/contests/abc153/tasks/abc153_f
 * @tags                greedy, data_structures, lazy_segtree, segment_tree
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 *
 * Observations:
 * 1. To kill a certain monster $i$, one needs `ceil(h[i]/A)` hits.
 * 2. To kill the first (leftmost) monster, it is optimal to attack at position
 * `x[1] + D`, because that would maximize potential hits to other monsters.
 * This would yield an attack area of `[x[1], x[1] + 2 * D]`.
 *
 * Using these  observations we can craft a greedy strategy to kill all
 * monsters with minimal attacks.
 *
 * 1. Sort monsters by their position `x`, in that way we can always know the
 * leftmost monster alive.
 * 2. For each alive monster `i` from left to right (3-4):
 * 3. Find the last monster j, that would be hit by the attack (obs. 2).
 * 4. Attack `x = ceil(h[i]/A)` times, yielding `A * x` damage to monsters
 * `[i, j]`.
 *
 * We can support operation $3$ with a binary search in $O(\log{n})$ and
 * operation $4$ with any range sum update algorithm. I chose to use a standard
 * lazy segment tree. This is another cool and simple implementation using a
 * queue, [cf-comment](https://codeforces.com/blog/entry/73374?#comment-576963).
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/lazysegtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct S
{
    int n;
    ll  sum;
};

S op(S a, S b) { return {a.n + b.n, a.sum + b.sum}; }

S e() { return {0, 0}; }

using F = ll;

S mapping(F f, S x) { return {x.n, x.sum + x.n * f}; }

F composition(F f, F g) { return f + g; }

F id() { return 0ll; }

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(ll d, ll a, vector<pair<ll, ll>> xh)
{
    using T = pair<ll, ll>;

    int                                                 n   = xh.size();
    ll                                                  ans = 0;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);

    sort(all(xh));
    for (int i = 0; i < n; ++i)
        seg.set(i, {1, xh[i].second});

    for (int i = 0; i < n; ++i)
    {
        auto it = upper_bound(all(xh), T{xh[i].first + 2 * d, 1e10});
        int  j  = distance(xh.begin(), it);
        ll   h  = seg.get(i).sum;
        if (h > 0)
        {
            int attacks = ceil(h, a);
            seg.apply(i, j, -a * attacks);
            ans += attacks;
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  d, a;
    cin >> n >> d >> a;

    vector<pair<ll, ll>> xh(n);
    for (auto &[x, h] : xh)
        cin >> x >> h;

    cout << solve(d, a, xh) << endl;

    return 0;
}
