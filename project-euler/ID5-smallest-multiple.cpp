/** @file
 * @date                2020-11-26
 * @url                 https://projecteuler.net/problem=5
 * @tags                math, lcm
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(n)
 * @memory_complexity   O(1)
 * @idea
 * LCM of 1-20 numbers.
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

int main(void)
{
    ll ans = 1;
    for (ll i = 2; i <= 20; ++i)
        ans = (ans * i) / gcd(ans, i);

    cout << ans << endl;
    return 0;
}
