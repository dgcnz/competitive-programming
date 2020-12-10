/** @file
 * @date                2020-12-10
 * @url                 https://atcoder.jp/contests/abc163/tasks/abc163_d
 * @tags                math, counting
 * @status              AC
 * @score               1
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       60
 * @coding_time         3
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * I'm kinda lazy to explain this problem, so here's the
 * [editorial](https://img.atcoder.jp/abc163/editorial.pdf)
 *
 * Anyhow, the key points are:
 * - Fix the quantity of numbers to sample, $i$, $k \leq i \leq n + 1$.
 * - Note that we can produce any number in between the minimum and maximum sum
 * of $i$ numbers.
 * - For each desired $i$ compute the size of the range described above.
 * - Note that those ranges do not overlap.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;

int const MOD = 1e9 + 7;

ll sq(ll n) { return (n * (n + 1)) / 2; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = k; i <= n + 1; ++i)
    {
        ans += sq(n) - sq(n - i) - sq(i - 1) + 1;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
