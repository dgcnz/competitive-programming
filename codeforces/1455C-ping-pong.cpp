/** @file
 * @date                2020-11-30
 * @url                 https://codeforces.com/contest/1455/problem/C
 * @tags                greedy
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       13
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Keep in mind that the first priority of each player is to maximize their
 * wins.
 *
 * Let's take the perspective of player $2$, Bob. Bob can win at most $y$,
 * times, by doing nothing and letting player $1$ run out of stamina. Can Bob
 * minimize Alice's wins without affecting his score?
 *
 * One way is to only respond on Alice's last serve (since she wouldn't be able
 * to respond anyway),. But we soon realize that's the only option.
 *
 * If Bob responds to any of Alice's $i \in {1, 2, ..., x - 1}$ serve, then
 * Alice's best chance is to not respond until Bob's last serve, $y$ (same
 * strategy). Alice would then win $(i - 1) + (x - i) = x - 1$  times and Bob $y
 * - 1$ times. This is suboptimal for Bob, since we know he can win $y$ times by
 * our optimal strategy.
 *
 * Since Alice is on Bob's mercy (she can't stop serving until she runs out of
 * stamina or Bob wins), Bob will choose the optimal strategy and win $y$ times
 * while Alice $x - 1$ times.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        cout << x - 1 << " " << y << endl;
    }
    return 0;
}
