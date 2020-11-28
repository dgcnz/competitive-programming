/** @file
 * @date                2020-11-27
 * @url                 https://codeforces.com/contest/148/problem/A
 * @tags                number_theory, factorization, brute_force
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         2
 * @time_complexity     O(d)
 * @memory_complexity   O(1)
 * @idea
 * Count all numbers [1, d] that are at least divisible by k, l, m or n.
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

    vi factors(4);

    for (auto &fi : factors)
        cin >> fi;

    int d, ans = 0;
    cin >> d;

    for (int i = 1; i <= d; ++i)
    {
        for (auto fi : factors)
        {
            if (i % fi == 0)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
