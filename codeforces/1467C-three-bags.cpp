/** @file
 * @date                2021-01-08
 * @url                 https://codeforces.com/contest/1467/problem/C
 * @tags                greedy
 * @status              AC
 * @score               1
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         60
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *
 * Observations
 * 1. $x - y = x + |y|$, given $x \geq 0$ and $y \leq 0$.
 * 2. So, if we have a bag with a number, $x$, and other bags with negative
 * numbers, it's the same as adding the absolute value of all numbers.
 * 3. Following this reasoning, we should find a way to separate a positive
 * number from the negative numbers in different bags.
 * 4. Given that all numbers are initially positive, we must force one to become
 * negative.
 * 5. Making $x$ negative, means doing $x - y$ given $x \leq y$. From our ideal
 * answer (observation 2.), we have a loss of $2x$. Meaning that if that
 * achieves our ideal state, then the answer is $\text{total sum} - 2x$.
 * 6. We ought to find a way to minimize this loss.
 *
 *
 * There are two cases that when considered achieve an optimal answer:
 * 1. Making an entire bag negative.
 * 2. Making the minimum of two bags negative.
 *
 * There should be a lot of edge cases in the implementation, but it just
 * magically works, idk.
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
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using vec2 = vector<vector<ll>>;

ll solve(vec2 a)
{
    ll         tot = 0;
    vector<ll> sum(3, 0);
    for (int i = 0; i < 3; ++i)
    {
        sort(all(a[i]), greater<ll>());
        tot += sum[i] = accumulate(all(a[i]), 0LL);
    }

    ll ans = max({tot - 2 * a[0].back() - 2 * a[1].back(),
                  tot - 2 * a[0].back() - 2 * a[2].back(),
                  tot - 2 * a[1].back() - 2 * a[2].back()});

    ans = max({ans, tot - 2 * sum[0], tot - 2 * sum[1], tot - 2 * sum[2]});
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    vec2 a(3);
    for (int i = 0; i < 3; ++i)
    {
        int n;
        cin >> n;
        a[i].resize(n);
    }
    for (auto &a_row : a)
        for (auto &aij : a_row)
            cin >> aij;

    cout << solve(a) << endl;
    return 0;
}
