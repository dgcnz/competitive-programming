/** @file
 * @date                2021-03-13
 * @url                 https://atcoder.jp/contests/abc195/tasks/abc195_c
 * @tags                math, brute_force
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * 1. For a given number with n digits, it requires `floor(d - 1 / 3)` commas.
 *
 * For all number of digits (1-9, 10-99, 100-999, ...), use 1) to add to the
 * answer.
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

ll solve(ll n)
{
    ll  x = 10, y = 1, ans = 0;
    int d = 1;
    while (x <= n)
    {
        ans += (x - y) * ((d - 1) / 3);
        x *= 10, y *= 10, d++;
    }
    // y < n <= x
    ans += (n - y + 1) * ((d - 1) / 3);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
