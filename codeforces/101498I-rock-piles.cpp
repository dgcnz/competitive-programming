/** @file
 *
 * @url                 https://codeforces.com/gym/101498/problem/I
 * @tags                game_theory, math
 *
 * @status              AC
 * @score               4
 * @difficulty          4
 * @editorial           no
 *
 * @reading_time        2
 * @thinking_time       30
 * @coding_time         2
 * @debug_time          0
 *
 * @time_complexity     [O(1))
 * @memory_complexity   [O(1)]
 * @idea
 *  [Maybe this is flawed, but it got AC. Nevertheless, here's my reasoning.]
 *  - Let's define:
 *      1. Even state: 2 piles have an even amount of rocks.
 *      2. Odd state: not even state.
 *  - If a player is on an even state, the second player can always force him to
 * be on even states.
 *  - So, since the end state has trivially an even state, then whoever
 * starts on an uneven state can force the second player to lose by keeping him
 * on even states.
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

    string ans[2] = {"hasan", "abdullah"};
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << ans[n % 2 == 0 and m % 2 == 0] << endl;
    }
    return 0;
}
