/** @file
 * @date                2020-12-17
 * @url                 https://codeforces.com/contest/1463/problem/A
 * @tags                math, easy
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         3
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Note that the total health of enemies has to be a multiple of 9 (6 + 3), if
 * you want to pass the dungeon beautifully.
 *
 * In such case, the total amount of enhance shots done will be $x =
 * \frac{s}{9}$, where $s$ denotes the total health of enemies.
 *
 * Note that the actual amount of enhanced shots possible is bounded by the
 * minimum health of all monsters (every enhanced shot forces us to reduce all
 * monster's health by 1). So, if $x \leq \min(a, b, c)$, there's always a way
 * to reduce the excess health with normal shots (given our previous assumption
 * that $s$ is a multiple of $9$).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(int a, int b, int c)
{
    int total = a + b + c;
    if (total % 9)
        return false;
    int shots = total / 9;
    return min({a, b, c}) >= shots;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (solve(a, b, c) ? "YES" : "NO") << endl;
    }
    return 0;
}
