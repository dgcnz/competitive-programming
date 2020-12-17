/** @file
 * @date                2020-12-11
 * @url                 https://atcoder.jp/contests/abc177/tasks/abc177_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * To arrive in time, this has to be true:
 * $$T >= \frac{D}{S}$$
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
    int d, t, s;
    cin >> d >> t >> s;
    cout << (((d + s - 1) / s <= t) ? "Yes" : "No") << endl;

    return 0;
}
