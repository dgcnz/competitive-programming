/** @file
 * @date                2021-01-02
 * @url                 https://atcoder.jp/contests/abc103/tasks/abc103_c
 * @tags                modulo, observation, lcm
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         5
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Imagine there exist a value $m$ such that it maximizes the contribution of
 * each term in the summation of $f$, meaning that $m \equiv a_i - 1 \mod a_i$
 * for all $i$.
 *
 * If such a value exists, then $m + 1$ must be divisible by all $a_i$. We know
 * an number with such properties exists, as the lcm of all $a_i$ behaves as an
 * $m + 1$. Therefore, the answer is:
 *
 * $$\sum_{i = 1}^n a_i - 1$$
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

ll solve(vi a) { return accumulate(all(a), 0LL) - isz(a); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n);

    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;

    return 0;
}
