/** @file
 * @date                2021-01-10
 * @url                 https://atcoder.jp/contests/abc188/tasks/abc188_a
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
 * $$|x - y| < 3$$
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
    int x, y;
    cin >> x >> y;
    string ans[2] = {"No", "Yes"};

    cout << (abs(x - y) < 3 ? "Yes" : "No") << endl;
    return 0;
}
