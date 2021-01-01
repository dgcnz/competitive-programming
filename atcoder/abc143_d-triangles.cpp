/** @file
 * @date                2020-12-24
 * @url                 https://atcoder.jp/contests/abc143/tasks/abc143_d
 * @tags                sorting, binary_search
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * If we have the length of the sticks, $l$, sorted non-decreasingly, we can
 * count all possible triangles by listing two sides $a$, and $b$ and finding
 * the position, $c$, where the length starts to become degenerate.
 *
 * Remember that $a + b > c$ and $a \leq b \leq c$.
 *
 * This can be done with binary search or two-pointers.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
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
    int n;
    cin >> n;
    vi l(n);
    for (auto &li : l)
        cin >> li;

    sort(all(l));

    int ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            auto it = lower_bound(begin(l) + j + 1, end(l), l[i] + l[j]);
            int  k  = distance(begin(l), it);
            if (k - 1 > j)
                ans += k - j - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
