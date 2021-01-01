/** @file
 * @date                2020-12-19
 * @url                 https://atcoder.jp/contests/abc186/tasks/abc186_e
 * @tags                number_theory, modulo, crt
 * @status              AC
 * @score               4
 * @difficulty          4
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       60
 * @coding_time         10
 * @time_complexity     O(\log{lcm(s, k)})
 * @memory_complexity   O(n)
 * @idea
 * Let the throne lie at position $0$ and Takahashi at position $S$. We want to
 * find:
 *
 * $$ s + xk \equiv 0 \mod n $$
 *
 * Furthermore, to simplify the problem, let $y = s + xk$, the position where
 * Takahashi first meets the Throne (if we were to count distance rather than
 * displacement). Assume that such a value exists.
 *
 * We can say a couple of things about $y$.
 * 1. $y$ will be at the Throne's position (after some number of laps around the
 * circle), or: $$y \equiv 0 \mod n$$
 * 2. $y$ is reachable by some number of $k$-displacements: $$y - s \equiv 0
 * \mod k$$
 *
 * If we arrange 2. to be $y \equiv s \mod k$ then we have two modular
 * congruencies that we can solve using the chinese remainder theorem.
 *
 * Having solved the modular equations, the only thing left to do is to solve
 * for $x$ in the aforementioned equivalence: $y=s+xk$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/math>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;

ll solve(ll n, ll s, ll k)
{
    auto [y, z] = atcoder::crt({0, s}, {n, k});
    if (z == 0)
        return -1;
    if (y < s)
        y += z;
    return (y - s) / k;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s, k;
        cin >> n >> s >> k;
        cout << solve(n, s, k) << endl;
    }
    return 0;
}
