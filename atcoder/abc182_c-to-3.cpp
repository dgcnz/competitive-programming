/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc182/tasks/abc182_c
 * @tags                implementation, math
 * @status              AC
 * @score               0
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         15
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Observations:
 * 1. For a number to be divisible by $3$ the sum of its digits must be
 * divisible by $3$.
 * 2. Removing two digits with the same remainder $r$ is equivalent to removing
 * remainder $3 - r$ from the overall digit sum.
 *
 * Say that a number $x$ has a digit sum equal to $s$ and $s$ has remainder $r$
 * when divided by $3$. Let's handle some of the cases.
 *
 * If $r$ is zero, then we're done.
 *
 * If there's a digit with remainder $r$ in $x$, we remove it and we're done.
 *
 * If there are two digits remainder $3 - r$, we remove then and we're done.
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

int solve(vi a)
{
    int n = isz(a);
    vi  rem(3, 0);
    for (auto ai : a)
        rem[ai % 3]++;

    int sum = accumulate(all(a), 0);

    if (sum % 3 == 0)
        return 0;

    if (n > 1 and rem[sum % 3])
        return 1;

    if (n > 2 and rem[3 - (sum % 3)] >= 2)
        return 2;

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string n;
    cin >> n;

    vi a(n.size());
    transform(all(n), begin(a), [](char c) { return c - '0'; });

    cout << solve(a) << endl;
    return 0;
}
