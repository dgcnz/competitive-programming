/** @file
 * @date                2020-11-23
 * @url                 https://atcoder.jp/contests/arc108/tasks/arc108_a
 * @tags                math, brute_force
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         5
 * @time_complexity     O( \sqrt{ \max(S, P)})
 * @memory_complexity   O(1)
 * @idea
 * - Write both equations in terms of one variable, N or M: $N^2 - NS + P = 0$.
 * - The problem reduces to finding a positive root of that expression.
 * - This problem could be solved by doing a binary search, but it would result
 * in integer overflow.
 * - Note, however, that $\max(N, M) <= \sqrt{max(S, P)}$.
 * - Since that value doesn't exceed $10^6$, we can linear search the answer.
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
using predicate = function<bool(ll)>;

bool solve(ll S, ll P)
{
    for (ll N = 1, MAX = 1e6; N <= MAX; ++N)
        if (N * (S - N) == P)
            return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll S, P;
    cin >> S >> P;

    cout << (solve(S, P) ? "Yes" : "No") << endl;
    return 0;
}
