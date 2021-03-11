/** @file
 * @date                2021-02-20
 * @url                 https://atcoder.jp/contests/abc192/tasks/abc192_a
 * @tags                math, easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        0
 * @thinking_time       1
 * @coding_time         0
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * ```
 * 100 - (x % 100)
 * ```
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int x;
    cin >> x;

    cout << 100 - (x % 100) << endl;

    return 0;
}
