/** @file
 * @date                2020-12-10
 * @url                 https://atcoder.jp/contests/arc102/tasks/arc102_a
 * @tags                counting
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * The key insight is to think about the remainders of $a, b, c$ when divided by
 * $k$.
 *
 * Trivially, picking $a, b, c$'s with remainder $0$ will yield multiples
 * of $k$ when added. However, when $k$ is even, we may also count numbers with
 * remainder $k / 2$.
 *
 * Note that no other numbers will contribute to the answer.
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

ll solve(int n, int k)
{
    auto ways = [](ll n) -> ll { return n * n * n; };

    ll mid = 0, zero = 0;
    for (int i = 1; i <= n; ++i)
    {
        mid += (k % 2 == 0 and i % k == (k / 2));
        zero += (i % k == 0);
    }
    return ways(zero) + ways(mid);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
