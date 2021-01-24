/** @file
 * @date                2021-01-18
 * @url                 https://cses.fi/problemset/task/2183
 * @tags                greedy, sorting, constructive
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         5
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Let's sort the elements in non-decreasing order and iterate them from
 * smallest to largest.
 *
 * While considering element $a_i$, assume that we can create all numbers
 * $1, 2, ..., x$, where $x$ is $\sum_{j = 1}^{i -1}a_j$. Note that by
 * considering $a_i$, we can construct numbers $a_i, a_i + 1, ..., x + a_i$.
 * Therefore, only if $x + 1 - a_i \leq 1$  would number $x + 1$ be possible to
 * construct. Otherwise, the smallest impossible coin sum is $x + 1$.
 *
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

ll solve(vi a)
{
    sort(all(a));

    ll sum = 0;
    for (auto ai : a)
    {
        if (ai > sum + 1)
            return sum + 1;
        sum += ai;
    }

    return sum + 1;
}

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
