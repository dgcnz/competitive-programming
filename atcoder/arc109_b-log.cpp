/** @file
 * @date                2020-11-28
 * @url                 https://atcoder.jp/contests/arc109/tasks/arc109_b
 * @tags                binary_search
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       8
 * @coding_time         10
 * @time_complexity     O(\log{n})
 * @memory_complexity   O(1)
 * @idea
 * Pick the log of size n + 1 and maximize the amount of logs from [1 ... m]
 * that can be cut from n + 1.
 *
 * $$ argmax_{m}((n + 1 - \sum_{i = 1}^{m} i) \geq 0) $$
 *
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll        = long long;
using ii        = pair<int, int>;
using vi        = vector<int>;
using predicate = function<bool(ll)>;

ll n;

inline bool ok(ll m) { return (2 * (n + 1)) / m >= m + 1; }

ll bs(ll l, ll r, predicate p)
{
    // 1 1 1 1 0 0 0 0 0 /last 1
    while (l < r)
    {
        ll m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;

    auto ans = bs(1, n, ok);

    cout << n - ans + 1 << endl;

    return 0;
}
