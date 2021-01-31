/** @file
 * @date                2021-01-23
 * @url                 https://atcoder.jp/contests/abc182/tasks/abc182_a
 * @tags                easy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       0
 * @coding_time         1
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * $2a + 100 - b$
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
    int a, b;
    cin >> a >> b;

    cout << 2 * a + 100 - b << endl;
    return 0;
}
