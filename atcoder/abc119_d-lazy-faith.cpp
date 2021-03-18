/** @file
 * @date                2021-03-16
 * @url                 https://atcoder.jp/contests/abc119/tasks/abc119_d
 * @tags                implementation, binary_search
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         20
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 *
 * For each query $i$ there are 4 possibilities based on the starting position
 * $x_i$:
 * 1. Visit a shrine and temple on the left.
 * 2. Visit a shrine and temple on the right.
 * 3. Visit a shrine on the left and a temple on the right.
 * 4. Visit a shrine on the right and a temple on the left.
 *
 * Taking the minimum distance traveled for those possibilities is the answer.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> s(n), t(m);
    for (auto &si : s)
        cin >> si;
    for (auto &ti : t)
        cin >> ti;

    ll const INF = 1e16;
    while (q--)
    {
        ll x, ans = INF;
        cin >> x;

        ll sr = INF, sl = INF, tr = INF, tl = INF;
        if (auto it = lower_bound(all(s), x); it != s.end())
            sr = abs(*it - x);
        if (auto it = lower_bound(all(t), x); it != t.end())
            tr = abs(*it - x);
        if (auto it = upper_bound(all(s), x); it != s.begin())
            sl = abs(*prev(it) - x);
        if (auto it = upper_bound(all(t), x); it != t.begin())
            tl = abs(*prev(it) - x);

        ans = min(ans, max(sr, tr));
        ans = min(ans, max(sl, tl));
        ans = min(ans, 2 * min(sl, tr) + max(sl, tr));
        ans = min(ans, 2 * min(sr, tl) + max(sr, tl));
        cout << ans << endl;
    }
    return 0;
}
