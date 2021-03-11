/** @file
 * @date                2021-01-31
 * @url                 https://atcoder.jp/contests/abc181/tasks/abc181_c
 * @tags                sorting, brute_force, implementation
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         20
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Let's sort the students by their heights. Without the teacher the optimal
 * answer would be the sum of differences on the sorted array.
 *
 * For each $m$ heights for the teacher, we need to find where should be placed
 * to provide an optimal solution for that given height. Out of all, we'll pick
 * the best.
 *
 * We can build two arrays that that maintain the difference sum for the prefix
 * up to $i$ and the suffix until $i$. To find the optimal placement of the
 * teacher given height $j$, we shall binary search the place where it should be
 * placed in order to keep the array sorted. Given that new position, we can use
 * our prefix and suffix array to answer get the answer.
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

ll solve(vi h, vi w)
{
    int n = h.size();

    sort(all(h), greater<int>());

    vector<ll> rans(n), lans(n);
    rans[n - 1] = h[n - 1], lans[0] = h[0];

    for (int i = n - 2; i >= 0; --i)
        rans[i] = h[i] - rans[i + 1];

    for (int i = 1; i < n; ++i)
        lans[i] = lans[i - 1] + h[i] * (i % 2 == 0 ? +1 : -1);

    ll ans = 1e15;
    for (auto wi : w)
    {
        auto it = lower_bound(all(h), wi, greater<int>());
        ll   cur;
        if (it == h.end())
            cur = lans[n - 1] - wi;
        else if (it == h.begin())
            cur = wi - rans[0];
        else
        {
            int i = distance(begin(h), it);
            if (i % 2 == 0)
                cur = lans[i - 1] + wi - rans[i];
            else
                cur = lans[i - 1] - wi + rans[i];
        }
        ans = min(ans, cur);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vi h(n), w(m);
    for (auto &hi : h)
        cin >> hi;
    for (auto &wi : w)
        cin >> wi;

    cout << solve(h, w) << endl;
    return 0;
}
