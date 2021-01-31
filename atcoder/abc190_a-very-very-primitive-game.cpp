/** @file
 * @date                2021-01-30
 * @url                 https://atcoder.jp/contests/abc190/tasks/abc190_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         3
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
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
    string ans[2] = {"Aoki", "Takahashi"};
    int    a, b, c;
    cin >> a >> b >> c;

    if (c == 0)
        cout << ans[a > b] << endl;
    else
        cout << ans[a >= b] << endl;
    return 0;
}
