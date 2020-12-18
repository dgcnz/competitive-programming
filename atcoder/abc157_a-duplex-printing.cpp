/** @file
 * @date                2020-12-18
 * @url                 https://atcoder.jp/contests/abc157/tasks/abc157_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        0
 * @thinking_time       0
 * @coding_time         1
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * You need $\frac{(n + 1)}{2}$ pages.
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;

    cin >> n;
    cout << (n + 1) / 2 << endl;
    return 0;
}
