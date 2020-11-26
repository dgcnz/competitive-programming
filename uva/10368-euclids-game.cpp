/** @file
 * @date                2020-11-24
 * @url
 * https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1309
 * @tags                number_theory, gcd
 * @status              AC
 * @score               4
 * @difficulty          2
 * @editorial           no
 * @reading_time        2
 * @thinking_time       8
 * @coding_time         4
 * @time_complexity     O( \log{n})
 * @memory_complexity   O(1)
 * @idea
 * For simplicity, let's assume $b \leq a$.
 *
 * - At any state the player has the option to take $[1, a / b]$ from $a$.
 * - Note that there's always a turning point, when $a$ becomes less than $b$.
 * - Let's call the current state $s_i$ and the next turning point state,
 * $s_n(i)$.
 * - We have two cases:
 *     1. $s_n(i)$ is a losing state $\to$ We take $a/b$ from $a$ to force the
 * next player to lose.
 *     2. $s_n(i)$ is a winning state. If $a / b \geq 2$, we take $a / b - 1$
 * and force the next player to take $b$, which leaves us in the winning state.
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
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(int a, int b)
{
    if (b == 0)
        return false;
    return !solve(b, a % b) || (a / b >= 2);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b;
    while (cin >> a >> b, a and b)
    {
        if (b > a)
            swap(a, b);
        cout << (solve(a, b) ? "Stan" : "Ollie") << " wins" << endl;
    }
    return 0;
}
