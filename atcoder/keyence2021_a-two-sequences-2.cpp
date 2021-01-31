/** @file
 * @date                2021-01-16
 * @url https://atcoder.jp/contests/keyence2021/tasks/keyence2021_c
 * @tags                data_structures, segment_tree, greedy
 * @status              AC
 * @score               3
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         4
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Disclaimer: I was sleepy and segtree was the first thing that came to my
 * mind, don't judge me :(.
 *
 * Observations:
 * - For each $c_k$ we have two options. Either we pick $1 \leq i \leq j < k$
 * (which is $c_{i - 1}$) or we pick $b_j$ ($j = k$) and pair it with the
 * maximum $a_i$, $1 \leq i \leq j$.
 *
 * We can code a straightforward greedy with this.
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
using vll = vector<ll>;

using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return -1; }

vll solve(vll a, vll b)
{
    int n = isz(a);
    vll c(n);

    c[0] = a[0] * b[0];

    using RMQ = atcoder::segtree<S, op, e>;

    RMQ st(a);
    for (int i = 1; i < n; ++i)
        c[i] = max(c[i - 1], b[i] * st.prod(0, i + 1));

    return c;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vll a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    auto c = solve(a, b);
    for (auto ci : c)
        cout << ci << endl;
    return 0;
}
