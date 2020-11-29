/** @file
 * @date                2020-11-26
 * @url                 https://projecteuler.net/problem=6
 * @tags                math
 * @status              AC
 * @score               1
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       5
 * @coding_time         2
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * Use the closed formulas to compute terms.
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
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n = 100;
    ll a = (n * (n + 1) * (2 * n + 1)) / 6;
    ll b = (n * (n + 1)) / 2;
    cout << b * b - a << endl;
    return 0;
}
