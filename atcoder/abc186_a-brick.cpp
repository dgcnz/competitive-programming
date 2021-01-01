/** @file
 * @date                2020-12-19
 * @url                 https://atcoder.jp/contests/abc186/tasks/abc186_a
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
 * $$ floor(\frac{n}{w}) $$
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, w;
    cin >> n >> w;

    cout << n / w << endl;
    return 0;
}
